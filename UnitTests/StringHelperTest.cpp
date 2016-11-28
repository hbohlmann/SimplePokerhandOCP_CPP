#include "gtest/gtest.h"
#import "StringHelper.h"

class StringHelperTest : public ::testing::Test {

};


TEST(StringHelper_Test, SplitsStringsBySpace) {
    std::vector<std::string> splitted;
    std::string myString = "foo bar";
    split(myString, splitted);
    EXPECT_EQ("foo", splitted[0]);
    EXPECT_EQ("bar", splitted[1]);
}
