/**
 * vlan implementation for the packet header C++ Library
 *
 * This file is automatically generated by the library code generator.
 * Do not edit this file manually.
 **/

#include "vlan.hpp"

namespace libpacket::protocol {

/**
 * vlan getter implementations
 **/

enum vlan::priority_value get_vlan_priority(const vlan& header) noexcept
{
    auto tmp = header.priority_drop_eligible_id.load<uint16_t>() & 0xe000;
    tmp >>= 13;
    return (static_cast<enum vlan::priority_value>(tmp));
}

bool get_vlan_drop_eligible(const vlan& header) noexcept
{
    auto tmp = header.priority_drop_eligible_id.load<uint16_t>() & 0x1000;
    tmp >>= 12;
    return (static_cast<bool>(tmp));
}

uint16_t get_vlan_id(const vlan& header) noexcept
{
    auto tmp = header.priority_drop_eligible_id.load<uint16_t>() & 0xfff;
    return (tmp);
}

uint16_t get_vlan_ether_type(const vlan& header) noexcept
{
    auto tmp = header.ether_type.load<uint16_t>();
    return (tmp);
}

/**
 * vlan setter implementations
 **/

void set_vlan_priority(vlan& header, enum vlan::priority_value value) noexcept
{
    auto tmp = static_cast<uint16_t>(value);
    tmp <<= 13;
    header.priority_drop_eligible_id.store(static_cast<uint16_t>(((tmp & 0xe000) | (header.priority_drop_eligible_id.load<uint16_t>() & ~0xe000))));
}

void set_vlan_drop_eligible(vlan& header, bool value) noexcept
{
    auto tmp = static_cast<uint16_t>(value);
    tmp <<= 12;
    header.priority_drop_eligible_id.store(static_cast<uint16_t>(((tmp & 0x1000) | (header.priority_drop_eligible_id.load<uint16_t>() & ~0x1000))));
}

void set_vlan_id(vlan& header, uint16_t value) noexcept
{
    header.priority_drop_eligible_id.store(static_cast<uint16_t>(((value & 0xfff) | (header.priority_drop_eligible_id.load<uint16_t>() & ~0xfff))));
}

void set_vlan_ether_type(vlan& header, uint16_t value) noexcept
{
    header.ether_type.store(value);
}

/**
 * vlan field translate implementation
 **/

template <typename Key, typename Value, typename... Pairs>
constexpr auto associative_array(Pairs&&... pairs)
    -> std::array<std::pair<Key, Value>, sizeof... (pairs)>
{
    return {{std::forward<Pairs>(pairs)...}};
}

enum vlan::field_name vlan::get_field_name(std::string_view name) noexcept
{
    constexpr auto field_names = associative_array<std::string_view, vlan::field_name>(
        std::pair("priority", vlan::field_name::priority),
        std::pair("drop_eligible", vlan::field_name::drop_eligible),
        std::pair("id", vlan::field_name::id),
        std::pair("ether_type", vlan::field_name::ether_type));

    auto cursor = std::begin(field_names), end = std::end(field_names);
    while (cursor != end) {
        if (cursor->first == name) return (cursor->second);
        cursor++;
    }

    return (vlan::field_name::none);
}

const std::type_info& vlan::get_field_type(vlan::field_name field) noexcept
{
    switch (field) {
        case vlan::field_name::priority:
            return (typeid(uint16_t));
        case vlan::field_name::drop_eligible:
            return (typeid(uint16_t));
        case vlan::field_name::id:
            return (typeid(uint16_t));
        case vlan::field_name::ether_type:
            return (typeid(uint16_t));
        default:
            return (typeid(nullptr));
    }
}

}
