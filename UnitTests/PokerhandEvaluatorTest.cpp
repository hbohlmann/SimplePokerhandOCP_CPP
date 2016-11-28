#include "gtest/gtest.h"
#include "PokerhandEvaluator.h"

class PokerhandEvaluatorTest : public ::testing::Test {
public:
    PokerhandEvaluator evaluator;
};


TEST_F(PokerhandEvaluatorTest, FindsHighcardOutOfTwo) {
    EXPECT_EQ("C3", evaluator.evaluate("C2 C3"));
    EXPECT_EQ("C4", evaluator.evaluate("C2 C4"));
    EXPECT_EQ("C4", evaluator.evaluate("C4 C2"));
}


TEST_F(PokerhandEvaluatorTest, FindsHighcardIgnoringColor) {
    EXPECT_EQ("C3", evaluator.evaluate("H2 C3"));
}

TEST_F(PokerhandEvaluatorTest, FindsHighcardWith10) {
    EXPECT_EQ("C10", evaluator.evaluate("C9 C10"));
}


TEST_F(PokerhandEvaluatorTest, FindsHighcardWithFaceCards) {
    EXPECT_EQ("CJ", evaluator.evaluate("C10 CJ"));
    EXPECT_EQ("CQ", evaluator.evaluate("CJ CQ"));
    EXPECT_EQ("CK", evaluator.evaluate("CQ CK"));
    EXPECT_EQ("CA", evaluator.evaluate("CK CA"));
}

TEST_F(PokerhandEvaluatorTest, FindPair) {
    EXPECT_EQ("C2 H2", evaluator.evaluate("C2 H2"));
    EXPECT_EQ("C2 H2", evaluator.evaluate("C2 H2 C3"));
}
