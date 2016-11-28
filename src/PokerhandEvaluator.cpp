#include "PokerhandEvaluator.h"
#include "HighcardRule.h"
#include "PairRule.h"

PokerhandEvaluator::PokerhandEvaluator() {
	rules.push_back(new PairRule());
	rules.push_back(new HighcardRule());
}

string PokerhandEvaluator::evaluate(string hand) {
    vector<Card> cards = CardsFromString(hand);
    vector<Card> evaluated = evaluateCards(cards);
    return CardsToString(evaluated);
}

vector<Card> PokerhandEvaluator::evaluateCards(vector<Card> cards) {
    vector<Card> evaluated;

	vector<PokerRule*>::iterator it = rules.begin();
	while (evaluated.empty() && it != rules.end()) {
		PokerRule *rule = *it++;
		evaluated = rule->evaluateRule(cards);
	}

    return evaluated;
}

vector<Card> PokerhandEvaluator::findHighcard(vector<Card> cards) {
	PokerRule *rule = new HighcardRule();
	return rule->evaluateRule(cards);
}

vector<Card> PokerhandEvaluator::findPair(vector<Card> cards) {
	PokerRule *rule = new PairRule();
	return rule->evaluateRule(cards);
}

