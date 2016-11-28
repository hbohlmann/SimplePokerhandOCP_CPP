#import "gtest/gtest.h"
#include "Card.h"

TEST(CardTest, CreateCardsFromString) {
    std::vector<Card> cards = CardsFromString("C2 C3");
    Card c2 = {"C2"};
    Card c3 = {"C3"};
    EXPECT_EQ(c2, cards[0]);
    EXPECT_EQ(c3, cards[1]);
}

TEST(CardTest, CreateStringFromCards) {
    std::vector<Card> cards = CardsFromString("C2 C3");
    std::string string = CardsToString(cards);
    EXPECT_EQ("C2 C3", string);
}

TEST(CardTest, ComparesCardsByRank) {
    Card c2 = {"C2"};
    Card c3 = {"C3"};
    EXPECT_LT(c2, c3);
    EXPECT_GT(c3, c2);
}
