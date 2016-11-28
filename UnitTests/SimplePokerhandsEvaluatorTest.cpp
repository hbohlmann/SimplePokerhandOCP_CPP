#include "gtest/gtest.h"

#include "SimplePokerhandEvaluator.h"

struct SimplePokerhandEvaluatorTest : testing::Test {
	SimplePokerhandEvaluator poker;
};

TEST_F(SimplePokerhandEvaluatorTest, FindsHighcardFromTwo) {
	ASSERT_EQ(poker.evaluateHand("C2 C3"), "C3");
	ASSERT_EQ(poker.evaluateHand("C2 C4"), "C4");
	ASSERT_EQ(poker.evaluateHand("C4 C3"), "C4");
}

TEST_F(SimplePokerhandEvaluatorTest, FindsHighcardFromMoreThanTwo) {
	ASSERT_EQ(poker.evaluateHand("C2 C3 C4"), "C4");
}

TEST_F(SimplePokerhandEvaluatorTest, FindsHighcardIgnoringColor) {
	ASSERT_EQ(poker.evaluateHand("H2 C3"), "C3");
}

TEST_F(SimplePokerhandEvaluatorTest, FindsHighcardWith10) {
	ASSERT_EQ(poker.evaluateHand("C9 C10"), "C10");
}

TEST_F(SimplePokerhandEvaluatorTest, FindsHighcardWithFacecards) {
	ASSERT_EQ(poker.evaluateHand("C10 CJ"), "CJ");
	ASSERT_EQ(poker.evaluateHand("CJ CQ"), "CQ");
	ASSERT_EQ(poker.evaluateHand("CQ CK"), "CK");
	ASSERT_EQ(poker.evaluateHand("CK CA"), "CA");
}
