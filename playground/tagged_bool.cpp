#include "doctest_proxy.hpp"
#include <ak_toolkit/tagged_bool.hpp>
#include <string>

namespace xplicit = ak_toolkit::xplicit;

using namespace std;

using readonly = xplicit::tagged_bool<struct readonly_tag>;
using shared   = xplicit::tagged_bool<struct shared_tag>;

string param_spy{};

void make_file(readonly _readonly, shared _shared)
{
    if(_readonly) param_spy += "r";
    else param_spy += "rw";

    if(_shared) param_spy += "s";
    else param_spy += "ns";
}

suite_begin("tagged_bool");

test_case("ctor")
{
    const readonly a{true};
    const shared b{a};

    check_eq(b, shared{true});
}

test_case("usage")
{
    param_spy.clear();

    subcase("readonly, shared")
    {
        make_file(readonly{true}, shared{true});

        check_eq(param_spy, string{"rs"});
    }
    subcase("!readonly, shared")
    {
        make_file(readonly{false}, shared{true});

        check_eq(param_spy, string{"rws"});
    }
    subcase("readonly, !shared")
    {
        make_file(readonly{true}, shared{false});

        check_eq(param_spy, string{"rns"});
    }
    subcase("!readonly, !shared")
    {
        make_file(readonly{false}, shared{false});

        check_eq(param_spy, string{"rwns"});
    }
}

suite_end();
