#include "HighcardRule.h"

vector<Card> HighcardRule::evaluateRule(vector<Card> cards) {
	vector<Card> evaluated;
	sort(cards.begin(), cards.end());
	Card highCard = cards.back();
	evaluated.push_back(highCard);
	return evaluated;
}
