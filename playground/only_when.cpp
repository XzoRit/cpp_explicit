#include "doctest_proxy.hpp"
#include "xplicit_proxy.hpp"
#include <type_traits>
#include <vector>

namespace {
class test_only_int {
public:
  test_only_int(only_int i) : m_i{i.get()} {}
  int m_i;
};
} // namespace

suite_begin("only_when");

test_case("only int") {
  static_assert(std::is_constructible<test_only_int, int>::value);
  static_assert(std::is_constructible<test_only_int, short>::value);
  static_assert(std::is_constructible<test_only_int, char>::value);
  static_assert(std::is_constructible<test_only_int, bool>::value);

  static_assert(!std::is_constructible<test_only_int, unsigned>::value);
  static_assert(!std::is_constructible<test_only_int, float>::value);
  static_assert(!std::is_constructible<test_only_int, double>::value);
}

suite_end();
