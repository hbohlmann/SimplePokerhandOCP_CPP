#ifndef SIMPLEPOKERHANDSRP_POKERHANDEVALUATOR_H
#define SIMPLEPOKERHANDSRP_POKERHANDEVALUATOR_H

#include <string>
#include <vector>
#include <map>
#include "Card.h"
#include "PokerRule.h"

using namespace std;

class PokerhandEvaluator {

public:
	PokerhandEvaluator();
    string evaluate(string hand);

private:
	vector<PokerRule*> rules;
    vector<Card> evaluateCards(vector<Card> cards);
	vector<Card> findHighcard(vector<Card> cards);
	vector<Card> findPair(vector<Card> vector);
    map<int, vector<Card>> makeRankHistogram(vector<Card> cards);
    vector<Card> findCardsWithSameRankOfCount(int count, map<int, vector<Card>> histogram);
};


#endif //SIMPLEPOKERHANDSRP_POKERHANDEVALUATOR_H
