#define DOCTEST_CONFIG_COLORS_NONE
#define DOCTEST_CONFIG_NO_SHORT_MACROS
#define DOCTEST_CONFIG_NO_TRY_CATCH_IN_ASSERTS
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include <doctest.h>

#define check_eq    DOCTEST_FAST_CHECK_EQ
#define subcase     DOCTEST_SUBCASE
#define suite_begin DOCTEST_TEST_SUITE_BEGIN
#define suite_end   DOCTEST_TEST_SUITE_END
#define test_case   DOCTEST_TEST_CASE

