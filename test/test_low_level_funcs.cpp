#include <gtest/gtest.h>
#include <libminimal/libminimal.h>

class TestLowLevelFuncs : public ::testing::Test {
protected:
    int the_first_int;
    int the_second_int;


    void SetUp() override {
        the_first_int = 3;
        the_second_int = 5;
    }
};


TEST_F(TestLowLevelFuncs, add) {
    int expected_output = the_first_int + the_second_int;

    int real_output = libminimal::low_level::add(the_first_int, the_second_int);
    EXPECT_EQ(expected_output, real_output);
}

