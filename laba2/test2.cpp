#include <gtest/gtest.h>
#include "include/Three.h"


TEST(test_1, test_init) {   
    Three s({'1', '1', '1'});
    Three s1("111");
    ASSERT_TRUE(s == s1);
}
TEST(test_2, test_init) {   
    Three s({'0','1','1'});
    Three s1{"011"};
    ASSERT_TRUE(s == s1);
}
TEST(test_3, test_init) {   
    Three s(5,'1');
    Three s1({'1','1','1', '1', '1'});
    ASSERT_TRUE(s == s1);
}

TEST(test_4, test_init) {   
    Three s({'1'});
    Three s1("00001");
    ASSERT_TRUE(s == s1);
}

TEST(test_5, test_init) {
    ASSERT_THROW(Three s(1, '3'), std::underflow_error);
}

TEST(test_6, test_init) {
    ASSERT_THROW(Three s("312"), std::underflow_error);
}

TEST(test_7, test_init) {
    ASSERT_THROW(Three s({'3'}), std::underflow_error);
}

TEST(test_8, test_init) {
    Three s("12210");
    Three s1(s);
    ASSERT_TRUE(s == s1);
}

TEST(test_9, test_init) {
    Three s("10102");
    Three s1("10102");
    Three s2(std::move(s));
    ASSERT_TRUE(s1 == s2);
}

TEST(test_9, test_init) {
    Three s("10102");
    Three s1("10102");
    Three s2(std::move(s));
    ASSERT_TRUE(s1 == s2);
}

TEST(test_10, test_init) {
    Three s("10102");
    Three s1 = s;
    ASSERT_TRUE(s == s1);
}

TEST(test_11, test_init) {
    Three s;
    Three s1(5, '0');
    ASSERT_TRUE(s == s1);
}

TEST(test_12, test_init) {
    Three s;
    Three s1(5, '0');
    ASSERT_TRUE(s1 == s);
}

TEST(test_13, test_init) {
    Three s;
    Three s1(5, '1');
    ASSERT_TRUE(s != s1);
}
TEST(test_14, test_init) {
    Three s;
    Three s1({'1'});
    ASSERT_TRUE(s1 != s);
}

TEST(test_1, test_eq) {
    Three s;
    Three s1({'0'});
    ASSERT_TRUE(s1 == s);
}
TEST(test_2, test_eq) {
    Three s;
    Three s1({'1'});
    ASSERT_TRUE(s1 > s);
}

TEST(test_3, test_eq) {
    Three s("12");
    Three s1("100");
    ASSERT_TRUE(s1 > s);
}

TEST(test_4, test_eq) {
    Three s("102");
    Three s1("100");
    ASSERT_TRUE(s1 < s);
}

TEST(test_5, test_eq) {
    Three s("12");
    Three s1("100");
    ASSERT_TRUE(s1 >= s);
}
TEST(test_6, test_eq) {
    Three s("102");
    Three s1("100");
    ASSERT_TRUE(s1 <= s);
}
TEST(test_7, test_eq) {
    Three s("12");
    Three s1("100");
    ASSERT_TRUE(s1 != s);
}
TEST(test_8, test_eq) {
    Three s("12");
    Three s1("100");
    ASSERT_TRUE(s1 != s);
}
TEST(test_9, test_eq) {
    Three s("12");
    Three s1("100");
    s1 = s;
    ASSERT_TRUE(s1 == s);
}

TEST(test_1, test_math) {
    Three s("100");
    Three s1("11");
    Three s2("111");
    ASSERT_TRUE(s + s1 == s2);
}

TEST(test_2, test_math) {
    Three s("1");
    Three s1("11");
    Three s2("12");
    ASSERT_TRUE(s + s1 == s2);
}

TEST(test_3, test_math) {
    Three s("1");
    Three s1("12");
    Three s2("20");
    ASSERT_TRUE(s + s1 == s2);
}

TEST(test_4, test_math) {
    Three s("2222");
    Three s1("222");
    Three s2("10221");
    ASSERT_TRUE(s + s1 == s2);
}

TEST(test_5, test_math) {
    Three s("1000000");
    Three s1("1");
    Three s2("1000001");
    ASSERT_TRUE(s + s1 == s2);
}

TEST(test_6, test_math) {
    Three s("122");
    Three s1("1");
    Three s2("200");
    ASSERT_TRUE(s + s1 == s2);
}
TEST(test_7, test_math) {
    Three s("121");
    Three s1("1");
    Three s2("122");
    ASSERT_TRUE(s + s1 == s2);
}

TEST(test_8, test_math) {
    Three s("0");
    Three s1("111");
    Three s2("111");
    ASSERT_TRUE(s + s1 == s2);
}
TEST(test_9, test_math) {
    Three s("100");
    Three s1("11");
    Three s2("12");
    ASSERT_TRUE(s - s1 == s2);
}

TEST(test_10, test_math) {
    Three s("12");
    Three s1("11");
    Three s2("1");
    ASSERT_TRUE(s - s1 == s2);
}

TEST(test_11, test_math) {
    Three s("100");
    Three s1("22");
    Three s2("1");
    ASSERT_TRUE(s - s1 == s2);
}

TEST(test_12, test_math) {
    Three s("10221");
    Three s1("222");
    Three s2("2222");
    ASSERT_TRUE(s - s1 == s2);
}

TEST(test_13, test_math) {
    Three s("1000001");
    Three s1("1");
    Three s2("1000000");
    ASSERT_TRUE(s - s1 == s2);
}

TEST(test_14, test_math) {
    Three s("200");
    Three s1("1");
    Three s2("122");
    ASSERT_TRUE(s - s1 == s2);
}
TEST(test_15, test_math) {
    Three s("200");
    Three s1("200");
    Three s2("0");
    ASSERT_TRUE(s - s1 == s2);
}

TEST(test_16, test_math) {
    Three s("0");
    Three s1("0");
    Three s2("0");
    ASSERT_TRUE(s - s1 == s2);
}

TEST(test_17, test_math) {
    Three s("0");
    Three s1("0");
    Three s2("0");
    ASSERT_TRUE(s + s1 == s2);
}

TEST(test_18, test_math) {
    Three s("0");
    Three s1("1");

    ASSERT_THROW(s - s1, std::invalid_argument);
}


TEST(test_19, test_math) {
    Three s("2222");
    Three s1("222");
    s1 += s;
    Three s2("10221");
    ASSERT_TRUE(s1 == s2);
}

TEST(test_20, test_math) {
    Three s("1000001");
    Three s1("1");
    s1 -= s;
    Three s2("1");
    ASSERT_TRUE(s1 == s2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}