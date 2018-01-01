#include "doctest_proxy.hpp"
#include "xplicit_proxy.hpp"

namespace
{
    int param_spy{};

    void need_raw_pointer(not_null<int*> a)
    {
        param_spy = *a;
    }
}

suite_begin("not_null");

test_case("raw pointer")
{
    need_raw_pointer(as_not_null(new int{1}));
    check_eq(param_spy, 1);
}

test_case("2")
{
}

suite_end();
