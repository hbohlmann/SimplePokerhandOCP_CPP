#include "gtest/gtest.h"
#include "Card.h"
#include <vector>

struct CardTest : testing::Test {
	
};

TEST_F(CardTest, CanBeBuildFromString) {
	Card card("C3");
	ASSERT_EQ(card.getValue(), "C3");
}

TEST_F(CardTest, CanBeCompared) {
	Card card1("C2");
	Card card2("C3");
	ASSERT_TRUE(card1 < card2);
	ASSERT_TRUE(card2 > card1);
	ASSERT_TRUE(!(card2 == card1));
}

TEST_F(CardTest, IgnoresColorWhenCompared) {
	Card card1("H2");
	Card card2("C3");
	ASSERT_TRUE(card1 < card2);
}

TEST_F(CardTest, CanBeBuildFromStrings) {
	std::vector<Card> cards = CardsFromString("C2 C3");
	ASSERT_EQ(cards.size(), 2);
}
