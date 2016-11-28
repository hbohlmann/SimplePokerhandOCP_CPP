#ifndef PairRule_h
#define PairRule_h

#include "PokerRule.h"
#include <map>

class PairRule : public PokerRule {

public:
	vector<Card> evaluateRule(vector<Card> cards);

private:
	map<int, vector<Card>> makeRankHistogram(vector<Card> cards);
	vector<Card> findCardsWithSameRankOfCount(int count, map<int, vector<Card>> histogram);
};
#endif /* PairRule_h */
