#ifndef HighcardRule_h
#define HighcardRule_h

#include "PokerRule.h"

using namespace std;

class HighcardRule : public PokerRule {
	
public:
	vector<Card> evaluateRule(vector<Card> cards);
};

#endif /* HighcardRule_h */
