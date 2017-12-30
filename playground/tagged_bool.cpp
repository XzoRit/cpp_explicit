#include <ak_toolkit/tagged_bool.hpp>
#include <doctest.h>
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

TEST_CASE("tagged_bool")
{
    param_spy.clear();

    SUBCASE("readonly, shared")
    {
        make_file(readonly(true), shared(true));

        CHECK(param_spy == string{"rs"});
    }
    SUBCASE("!readonly, shared")
    {
        make_file(readonly(false), shared(true));

        CHECK(param_spy == string{"rws"});
    }
    SUBCASE("readonly, !shared")
    {
        make_file(readonly(true), shared(false));

        CHECK(param_spy == string{"rns"});
    }
    SUBCASE("!readonly, !shared")
    {
        make_file(readonly(false), shared(false));

        CHECK(param_spy == string{"rwns"});
    }
}
