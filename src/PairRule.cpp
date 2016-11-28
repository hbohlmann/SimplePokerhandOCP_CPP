#include "PairRule.h"

vector<Card> PairRule::evaluateRule(vector<Card> cards) {
	map<int, vector<Card>> rankHistogram = makeRankHistogram(cards);
	vector<Card> pair = findCardsWithSameRankOfCount(2, rankHistogram);
	return pair;
}

map<int, vector<Card>> PairRule::makeRankHistogram(vector<Card> cards) {
	map<int, vector<Card>> histogram;
	for (auto &&card : cards) {
		int rank = card.getRank();
		vector<Card> rankCards = histogram[rank];
		rankCards.push_back(card);
		histogram[rank] = rankCards;
	}
	return histogram;
}

vector<Card> PairRule::findCardsWithSameRankOfCount(int count, map<int, vector<Card>> histogram) {
	for (map<int, vector<Card>>::iterator it = histogram.begin(); it != histogram.end(); ++it) {
		vector<Card> cards = it->second;
		if (cards.size() == count) {
			return cards;
		}
	}
	return vector<Card>();
};
