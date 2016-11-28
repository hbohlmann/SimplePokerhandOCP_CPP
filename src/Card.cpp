#include "Card.h"
#include "StringHelper.h"

std::vector<Card> CardsFromString(std::string hand) {
	std::vector<std::string> card_strings;
	StringHelper::split(hand, card_strings);
	std::vector<Card> cards;
	for (std::vector<std::string>::iterator it = card_strings.begin(); it != card_strings.end(); ++it) {
		std::string cardString = *it;
		Card card = {cardString};
		cards.push_back(card);
	}
	return cards;
}
