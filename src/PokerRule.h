#ifndef PokerRule_h
#define PokerRule_h

#include "Card.h"
#include <vector>

using namespace std;

struct PokerRule {
	virtual vector<Card> evaluateRule(vector<Card> cards) = 0;
};

#endif /* PokerRule_h */
