#include "Card.h"
#include "StringHelper.h"

std::vector<Card> CardsFromString(std::string cards) {
    std::vector<Card> result;
    std::vector<std::string> strings;
    split(cards, strings);
    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it) {
        std::string cardString = *it;
        Card card = {cardString};
        result.push_back(card);
    }
    return result;
}

std::string CardsToString(std::vector<Card> cards) {
    std::string cardString = "";
    for (std::vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        Card card = *it;
        cardString.append(card.value);
        cardString.append(" ");
    }
    return cardString.substr(0, cardString.length()-1);
}
