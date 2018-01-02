#include "doctest_proxy.hpp"
#include "xplicit_proxy.hpp"
#include <vector>

namespace
{
    template<class A>
    void assign(const A& from, out_param<A&> to)
    {
        to.get() = from;
    }
}

suite_begin("out_param");

test_case("assign")
{
    std::vector<int> a{1,3,5,7,9};
    assign({2,4,6,8}, out(a));

    check_eq(a, std::vector<int>{2,4,6,8});
}

suite_end();
