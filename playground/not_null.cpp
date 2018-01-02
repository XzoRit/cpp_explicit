#include "doctest_proxy.hpp"
#include "xplicit_proxy.hpp"
#include <memory>

namespace
{
    using namespace std;

    int param_spy{};

    void need_pointer(not_null<int*> a)
    {
        param_spy = *a;
    }

    void need_pointer(not_null<unique_ptr<int>> a)
    {
        param_spy = *a;
    }

    void need_pointer(not_null<shared_ptr<int>> a)
    {
        param_spy = *a;
    }
}

suite_begin("not_null");

test_case("raw pointer")
{
    need_pointer(as_not_null(new int{1}));
    check_eq(param_spy, 1);
}

test_case("unique pointer")
{
    need_pointer(as_not_null(std::make_unique<int>(2)));
    check_eq(param_spy, 2);
}

test_case("shared pointer")
{
    need_pointer(as_not_null(std::make_shared<int>(3)));
    check_eq(param_spy, 3);
}

suite_end();
