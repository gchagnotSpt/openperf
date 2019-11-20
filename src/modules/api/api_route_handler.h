#ifndef _OP_API_ROUTE_HANDLER_H_
#define _OP_API_ROUTE_HANDLER_H_

#include "pistache/router.h"
#include "core/op_init_factory.hpp"

namespace openperf {
namespace api {
namespace route {

struct handler : openperf::core::init_factory<handler, void *, Pistache::Rest::Router &>
{
    handler(Key) {};
    virtual ~handler() = default;
};

}
}
}

#endif /* _OP_API_ROUTE_HANDLER_ */
