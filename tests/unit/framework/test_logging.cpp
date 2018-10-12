#include <memory>

#include "zmq.h"
#include "catch.hpp"

#include "core/icp_core.h"

struct zmq_context_deleter {
    void operator()(void *context) const {
        zmq_ctx_term(context);
    }
};

TEST_CASE("check log level setter/getter", "[logging]") {
    for (int level = ICP_LOG_NONE; level <= ICP_LOG_MAX; level++) {
        icp_log_level_set(static_cast<enum icp_log_level>(level));
        REQUIRE(icp_log_level_get() == level);
    }
}

TEST_CASE("exercise logging thread functionality", "[logging]")
{
    std::unique_ptr<void, zmq_context_deleter> context(zmq_ctx_new());
    REQUIRE(context);
    REQUIRE(icp_log_init(context.get(), NULL) == 0);

    SECTION("verify log message submission") {
        REQUIRE(_icp_log(ICP_LOG_CRITICAL, __PRETTY_FUNCTION__,
                         "This is a critical message\n") == 0);
        REQUIRE(_icp_log(ICP_LOG_ERROR, __PRETTY_FUNCTION__,
                         "This is a error message\n") == 0);
        REQUIRE(_icp_log(ICP_LOG_WARNING, __PRETTY_FUNCTION__,
                         "This is a warning message\n") == 0);
        REQUIRE(_icp_log(ICP_LOG_INFO, __PRETTY_FUNCTION__,
                         "This is a info message\n") == 0);
        REQUIRE(_icp_log(ICP_LOG_DEBUG, __PRETTY_FUNCTION__,
                         "This is a debug message\n") == 0);
        REQUIRE(_icp_log(ICP_LOG_TRACE, __PRETTY_FUNCTION__,
                         "This is a trace message\n") == 0);
    }
}

TEST_CASE("check logging command line parsing function", "[logging]")
{
    /*
     * We need the const_cast to silence the compiler warning about
     * the string literal to char * const conversion.
     */
    SECTION("check long cli argument by number") {
        std::vector<char *> args = {
            const_cast<char *>("test_program"),
            const_cast<char *>("--log-level"),
            const_cast<char *>("2"),
            nullptr
        };
        REQUIRE(icp_log_level_find(args.size() - 1, args.data()) == ICP_LOG_ERROR);
    }

    SECTION("check long cli argument by name") {
        std::vector<char *> args = {
            const_cast<char *>("test_program"),
            const_cast<char *>("--log-level"),
            const_cast<char *>("warning"),
            nullptr
        };
        REQUIRE(icp_log_level_find(args.size() - 1, args.data()) == ICP_LOG_WARNING);
    }

    SECTION("check short cli argument by number") {
        std::vector<char *> args = {
            const_cast<char *>("test_program"),
            const_cast<char *>("-l"),
            const_cast<char *>("4"),
            nullptr
        };
        REQUIRE(icp_log_level_find(args.size() - 1, args.data()) == ICP_LOG_INFO);
    }

    SECTION("check short cli argument by name") {
        std::vector<char *> args = {
            const_cast<char *>("test_program"),
            const_cast<char *>("-l"),
            const_cast<char *>("DEBUG"),
            nullptr
        };
        REQUIRE(icp_log_level_find(args.size() - 1, args.data()) == ICP_LOG_DEBUG);
    }
}

TEST_CASE("check logging function signature --> string function", "[logging]")
{
    /* input, expected output pairs */
    std::vector<std::pair<const char *, const char *>> signatures = {
        { "int simple_function()",     "simple_function" },
        { "unsigned int ns::simple()", "ns::simple"      },
        { "std::vector<int>& crazy()", "crazy"           }
    };

    for(auto &pair : signatures) {
        char output[strlen(pair.first)];
        icp_log_function_name(pair.first, output);
        REQUIRE(strcmp(output, pair.second) == 0);
    }
}