#ifndef SIMPLEPOKERHANDOCP_CARD_H
#define SIMPLEPOKERHANDOCP_CARD_H


#include <string>
#include <vector>

struct Card {
    std::string value;

    bool operator==(const Card &other) const {
        return (value == other.value);
    }

    bool operator<(const Card &other) const {
        return getRank() < other.getRank();
    }

    bool operator>(const Card &other) const {
        return getRank() > other.getRank();
    }

    int getRank() const {
        std::string rankString = value.substr(1);
        if (rankString == "A") {
            return 14;
        }
        if (rankString == "K") {
            return 13;
        }
        if (rankString == "Q") {
            return 12;
        }
        if (rankString == "J") {
            return 11;
        }
        return std::stoi(rankString);
    }

};

std::vector<Card> CardsFromString(std::string cards);
std::string CardsToString(std::vector<Card>);

#endif //SIMPLEPOKERHANDOCP_CARD_H
