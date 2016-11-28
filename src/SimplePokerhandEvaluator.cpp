#include "SimplePokerhandEvaluator.h"
#include "StringHelper.h"

#include <stdlib.h>
#include "Card.h"

string SimplePokerhandEvaluator::evaluateHand(string hand) {
	vector<Card> cards = CardsFromString(hand);
	sort(begin(cards), end(cards));
	return cards.back().getValue();
}
