#include "PokerhandEvaluator.h"

string PokerhandEvaluator::evaluate(string hand) {
    vector<Card> cards = CardsFromString(hand);
    vector<Card> evaluated = evaluateCards(cards);
    return CardsToString(evaluated);
}

vector<Card> PokerhandEvaluator::evaluateCards(vector<Card> cards) {
    vector<Card> evaluated;

    evaluated = findPair(cards);

    if (evaluated.empty()) {
        Card highCard = findHighcard(cards);
		evaluated.push_back(highCard);
    }

    return evaluated;
}

Card PokerhandEvaluator::findHighcard(vector<Card> cards) {
	sort(cards.begin(), cards.end());
	Card highCard = cards.back();
	return highCard;
}

vector<Card> PokerhandEvaluator::findPair(vector<Card> cards) {
    map<int, vector<Card>> rankHistogram = makeRankHistogram(cards);
    vector<Card> pair = findCardsWithSameRankOfCount(2, rankHistogram);
    return pair;
}

map<int, vector<Card>> PokerhandEvaluator::makeRankHistogram(vector<Card> cards) {
    map<int, vector<Card>> histogram;
    for (auto &&card : cards) {
        int rank = card.getRank();
        vector<Card> rankCards = histogram[rank];
        rankCards.push_back(card);
        histogram[rank] = rankCards;
    }
    return histogram;
}

vector<Card> PokerhandEvaluator::findCardsWithSameRankOfCount(int count, map<int, vector<Card>> histogram) {
    for (map<int, vector<Card>>::iterator it = histogram.begin(); it != histogram.end(); ++it) {
        vector<Card> cards = it->second;
        if (cards.size() == count) {
            return cards;
        }
    }
    return vector<Card>();
};
