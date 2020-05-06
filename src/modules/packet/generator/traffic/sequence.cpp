#include "packet/generator/api.hpp"
#include "packet/generator/traffic/sequence.hpp"

namespace openperf::packet::generator::traffic {

namespace impl {

template <typename Template, template <typename T> class Strategy>
class sequence_generator
{
protected:
    using scalar_container = std::vector<unsigned>;
    scalar_container m_template_sizes;
    scalar_container m_template_scalars;

public:
    using view_type = std::pair<uint16_t, uint16_t>;
    using iterator = view_iterator<sequence_generator>;
    using const_iterator = const iterator;

    sequence_generator(const definition_container& definitions)
    {
        m_template_sizes.reserve(definitions.size());
        m_template_scalars.reserve(definitions.size());

        std::transform(std::begin(definitions),
                       std::end(definitions),
                       std::back_inserter(m_template_sizes),
                       [](auto&& item) {
                           const auto size = std::get<Template>(item).size();
                           assert(size <= std::numeric_limits<uint16_t>::max());
                           return (size);
                       });

        std::transform(std::begin(definitions),
                       std::end(definitions),
                       std::back_inserter(m_template_scalars),
                       [](auto&& item) { return (std::get<2>(item)); });
    }

    size_t size() const
    {
        return (static_cast<const Strategy<Template>&>(*this).get_size());
    }

    view_type operator[](size_t idx) const
    {
        return (static_cast<const Strategy<Template>&>(*this).get_indexes(idx));
    }

    iterator begin() { return (iterator(*this)); };
    const_iterator begin() const { return (iterator(*this)); };

    iterator end() { return (iterator(*this, size())); };
    const_iterator end() const { return (iterator(*this, size())); }
};

template <typename Template>
class round_robin final : public sequence_generator<Template, round_robin>
{
    using parent = sequence_generator<Template, round_robin>;
    typename parent::scalar_container m_weight_sums;

public:
    round_robin(const definition_container& definitions)
        : parent::sequence_generator(definitions)
    {
        m_weight_sums.reserve(parent::m_template_scalars.size());
        std::partial_sum(std::begin(parent::m_template_scalars),
                         std::end(parent::m_template_scalars),
                         std::back_inserter(m_weight_sums));
    }

    size_t get_size() const
    {
        return (std::inner_product(
            std::begin(parent::m_template_sizes),
            std::end(parent::m_template_sizes),
            std::begin(parent::m_template_scalars),
            0U,
            std::plus<size_t>{},
            [](unsigned lhs, unsigned rhs) { return (lhs * rhs); }));
    }

    typename parent::view_type get_indexes(size_t idx) const
    {
        const auto sum = m_weight_sums.back();
        auto quot = idx / sum;
        auto rem = idx % sum;

        auto tmp_idx = std::distance(std::begin(m_weight_sums),
                                     std::upper_bound(std::begin(m_weight_sums),
                                                      std::end(m_weight_sums),
                                                      rem));

        auto offset = quot * sum
                      + (tmp_idx == 0 ? 0 : m_weight_sums[tmp_idx - 1])
                      - quot * parent::m_template_scalars[tmp_idx];

        assert(static_cast<size_t>(offset) <= idx);

        return {tmp_idx, idx - offset};
    }
};

template <typename Template>
class sequential final : public sequence_generator<Template, sequential>
{
    using parent = sequence_generator<Template, sequential>;
    typename parent::scalar_container m_lengths;
    typename parent::scalar_container m_lengths_sums;

public:
    sequential(const definition_container& definitions)
        : parent::sequence_generator(definitions)
    {
        m_lengths.reserve(parent::m_template_scalars.size());
        m_lengths_sums.reserve(parent::m_template_scalars.size());

        std::transform(std::begin(parent::m_template_scalars),
                       std::end(parent::m_template_scalars),
                       std::begin(parent::m_template_sizes),
                       std::back_inserter(m_lengths),
                       [](unsigned lhs, unsigned rhs) { return (lhs * rhs); });

        std::partial_sum(std::begin(m_lengths),
                         std::end(m_lengths),
                         std::back_inserter(m_lengths_sums));
    }

    size_t get_size() const { return (m_lengths_sums.back()); }

    typename parent::view_type get_indexes(size_t idx) const
    {
        const auto sum = m_lengths_sums.back();
        auto quot = idx / sum;
        auto rem = idx % sum;

        auto tmp_idx = std::distance(
            std::begin(m_lengths_sums),
            std::upper_bound(
                std::begin(m_lengths_sums), std::end(m_lengths_sums), rem));

        auto offset = quot * sum
                      + (tmp_idx == 0 ? 0 : m_lengths_sums[tmp_idx - 1])
                      - quot * m_lengths[tmp_idx];

        assert(static_cast<size_t>(offset) <= idx);

        return {tmp_idx, idx - offset};
    }
};

} // namespace impl

sequence sequence::round_robin_sequence(definition_container&& definitions)
{
    return (sequence(std::forward<definition_container>(definitions),
                     order_type::round_robin));
}

sequence sequence::sequential_sequence(definition_container&& definitions)
{
    return (sequence(std::forward<definition_container>(definitions),
                     order_type::sequential));
}

sequence::sequence(definition_container&& definitions, order_type order)
{
    if (order == order_type::round_robin) {
        auto rr_packet_gen = impl::round_robin<packet_template>(definitions);
        m_packet_indexes.reserve(rr_packet_gen.size());
        std::copy(std::begin(rr_packet_gen),
                  std::end(rr_packet_gen),
                  std::back_inserter(m_packet_indexes));

        auto rr_length_gen = impl::round_robin<length_template>(definitions);
        m_length_indexes.reserve(rr_length_gen.size());
        std::copy(std::begin(rr_length_gen),
                  std::end(rr_length_gen),
                  std::back_inserter(m_length_indexes));
    } else {
        auto seq_packet_gen = impl::sequential<packet_template>(definitions);
        m_packet_indexes.reserve(seq_packet_gen.size());
        std::copy(std::begin(seq_packet_gen),
                  std::end(seq_packet_gen),
                  std::back_inserter(m_packet_indexes));

        auto seq_length_gen = impl::sequential<length_template>(definitions);
        m_length_indexes.reserve(seq_length_gen.size());
        std::copy(std::begin(seq_length_gen),
                  std::end(seq_length_gen),
                  std::back_inserter(m_length_indexes));
    }

    m_definitions.reserve(definitions.size());
    std::transform(
        std::begin(definitions),
        std::end(definitions),
        std::back_inserter(m_definitions),
        [](auto&& item) { return (std::forward<decltype(item)>(item)); });

    const auto& packet_templates = m_definitions.get<0>();
    m_flow_offsets.reserve(definitions.size());
    auto offset = 0U;
    std::transform(std::begin(packet_templates),
                   std::end(packet_templates),
                   std::back_inserter(m_flow_offsets),
                   [&](const auto& pt) {
                       auto tmp = offset;
                       offset += pt.size();
                       return (tmp);
                   });
}

uint16_t sequence::max_packet_length() const
{
    const auto& length_templates = m_definitions.get<1>();
    return (std::accumulate(std::begin(length_templates),
                            std::end(length_templates),
                            0U,
                            [](uint16_t lhs, const auto& rhs) {
                                return (std::max(lhs, rhs.max_packet_length()));
                            }));
}

size_t sequence::sum_packet_lengths() const
{
    const auto& length_templates = m_definitions.get<1>();
    return (std::accumulate(
        std::begin(m_length_indexes),
        std::end(m_length_indexes),
        0UL,
        [&](size_t lhs, const auto& rhs) {
            return (lhs + length_templates[rhs.first][rhs.second]);
        }));
}

size_t sequence::sum_packet_lengths(size_t idx) const
{
    const auto& length_templates = m_definitions.get<1>();
    auto q = lldiv(idx, m_length_indexes.size());

    auto sum = std::accumulate(
        std::begin(m_length_indexes),
        std::begin(m_length_indexes) + q.rem,
        0UL,
        [&](size_t lhs, const auto& rhs) {
            return (lhs + length_templates[rhs.first][rhs.second]);
        });

    if (q.quot) { sum += q.quot * sum_packet_lengths(); }

    return (sum);
}

bool sequence::has_signature_config() const
{
    const auto& signature_configs = m_definitions.get<3>();
    return (std::any_of(std::begin(signature_configs),
                        std::end(signature_configs),
                        [](const auto& item) { return (item.has_value()); }));
}

size_t sequence::flow_count() const
{
    const auto& packet_templates = m_definitions.get<0>();
    return (std::accumulate(
        std::begin(packet_templates),
        std::end(packet_templates),
        0UL,
        [](size_t lhs, const auto& rhs) { return (lhs + rhs.size()); }));
}

size_t sequence::size() const
{
    const auto& packet_templates = m_definitions.get<0>();
    const auto& length_templates = m_definitions.get<1>();
    return (std::lcm(packet_templates.size(), length_templates.size()));
}

namespace detail {

template <typename Function,
          typename FirstTuple,
          typename SecondTuple,
          size_t... Indexes>
constexpr void apply_two_impl(Function&& f,
                              FirstTuple&& x,
                              SecondTuple&& y,
                              std::index_sequence<Indexes...>)
{
    ((std::forward<Function>(f)(
         std::get<Indexes>(std::forward<FirstTuple>(x)),
         std::get<Indexes>(std::forward<SecondTuple>(y)))),
     ...);
}

template <typename Function, typename FirstTuple, typename SecondTuple>
constexpr void apply_two(Function&& f, FirstTuple&& x, SecondTuple&& y)
{
    apply_two_impl(
        std::forward<Function>(f),
        std::forward<FirstTuple>(x),
        std::forward<SecondTuple>(y),
        std::make_index_sequence<
            std::tuple_size_v<std::remove_reference_t<FirstTuple>>>{});
}

template <typename... OutputIt> class unzip_output_iterator
{
public:
    using iterator_category = std::output_iterator_tag;
    using value_type = void;
    using difference_type = void;
    using pointer = void;
    using reference = void;

    explicit unzip_output_iterator(OutputIt... cursors)
        : m_cursors(std::make_tuple(cursors...))
    {}

    unzip_output_iterator& operator*() { return (*this); }

    template <typename... Args>
    unzip_output_iterator& operator=(const std::tuple<Args...>& tuple)
    {
        detail::apply_two(
            [](auto&& cursor, auto&& arg) { *cursor = arg; }, m_cursors, tuple);
        return (*this);
    }

    unzip_output_iterator& operator++()
    {
        std::apply([](auto&&... cursor) { (++cursor, ...); }, m_cursors);
        return (*this);
    }

    unzip_output_iterator operator++(int)
    {
        auto to_return = *this;
        std::apply([](auto&&... cursor) { (cursor++, ...); }, m_cursors);
        return (to_return);
    }

private:
    std::tuple<OutputIt...> m_cursors;
};

} // namespace detail

template <typename... OutputIt> constexpr auto unzip(OutputIt... cursors)
{
    return (detail::unzip_output_iterator<OutputIt...>(cursors...));
}

/**
 * Handy function to transform ring like data
 */
template <typename InputIt,
          typename OutputIt,
          typename Size,
          typename TransformFn>
OutputIt ring_transform_n(InputIt first,
                          InputIt last,
                          InputIt cursor,
                          Size n,
                          OutputIt d_cursor,
                          TransformFn&& xform)
{
    const auto distance = std::distance(first, last);
    if (distance == 1) {
        d_cursor = std::fill_n(d_cursor, n, xform(*cursor++));
    } else {
        auto idx = 0U;
        while (idx++ < n) {
            *d_cursor++ = xform(*cursor++);
            if (cursor == last) { cursor = first; };
        }
    }

    return (d_cursor);
}

uint16_t sequence::unpack(size_t start_idx,
                          uint16_t count,
                          unsigned flow_indexes[],
                          const uint8_t* headers[],
                          packetio::packet::header_lengths header_lengths[],
                          packetio::packet::packet_type::flags header_flags[],
                          std::optional<signature_config> signature_configs[],
                          uint16_t pkt_lengths[]) const
{
    auto pkt_offset = start_idx % m_packet_indexes.size();
    const auto& packet_templates = m_definitions.get<0>();
    const auto& sig_configs = m_definitions.get<3>();

    ring_transform_n(std::begin(m_packet_indexes),
                     std::end(m_packet_indexes),
                     std::begin(m_packet_indexes) + pkt_offset,
                     count,
                     unzip(flow_indexes,
                           headers,
                           header_lengths,
                           header_flags,
                           signature_configs),
                     [&](const auto& pair) {
                         return (std::make_tuple(
                             m_flow_offsets[pair.first] + pair.second,
                             packet_templates[pair.first][pair.second],
                             packet_templates[pair.first].header_lengths(),
                             packet_templates[pair.first].header_flags(),
                             sig_configs[pair.first]));
                     });

    auto len_offset = start_idx % m_length_indexes.size();
    const auto& length_templates = m_definitions.get<1>();
    ring_transform_n(std::begin(m_length_indexes),
                     std::end(m_length_indexes),
                     std::begin(m_length_indexes) + len_offset,
                     count,
                     pkt_lengths,
                     [&](const auto& pair) {
                         return (length_templates[pair.first][pair.second]);
                     });

    return (count);
}

} // namespace openperf::packet::generator::traffic