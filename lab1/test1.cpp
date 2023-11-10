#include "googletest/googletest/include/gtest/gtest.h"
#include "conversion_time.cpp"

TEST(test_01, basic_tests)
{
    ASSERT_TRUE(conversion_time(1, 0, "pm") == "1300");
}

TEST(test_02, basic_tests)
{
    ASSERT_TRUE(conversion_time(12, 0, "am") == "1200");
}

TEST(test_03, basic_tests)
{
    ASSERT_TRUE(conversion_time(12, 0, "pm") == "0000");
}

TEST(test_04, basic_tests)
{
    ASSERT_TRUE(conversion_time(5, 33, "am") == "0533");
}

TEST(test_05, basic_tests)
{
    ASSERT_TRUE(conversion_time(5, 33, "pm") == "1733");
}

TEST(test_06, basic_tests)
{
    ASSERT_TRUE(conversion_time(7, 5, "am") == "0705");
}

TEST(test_07, basic_tests)
{
    ASSERT_TRUE(conversion_time(7, 5, "pm") == "1905");
}

TEST(test_08, basic_tests)
{
    ASSERT_TRUE(conversion_time(10, 10, "pm") == "2210");
}

TEST(test_09, basic_tests)
{
    ASSERT_TRUE(conversion_time(10, 10, "am") == "1010");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}