#include "doctest_proxy.hpp"
#include "xplicit_proxy.hpp"
#include <string>

namespace
{
using namespace std;

string param_spy{};

void make_file()
{
    param_spy = "1";
}
}

suite_begin("not_null");

test_case("1")
{
    check_eq(1, 2);
}

test_case("2")
{
}

suite_end();
