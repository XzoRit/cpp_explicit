#include "doctest_proxy.hpp"
#include "xplicit_proxy.hpp"

namespace
{
    int param_spy{};

    void need_pointer()
    {
        param_spy = 2;
    }

}

suite_begin("out_param");

test_case("raw pointer")
{
    check_eq(param_spy, 1);
}

suite_end();
