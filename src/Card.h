#ifndef Card_hpp
#define Card_hpp

#include <string>
#include <vector>

struct Card {
private:
	std::string _value;
	
public:
	Card(std::string value) { _value = value; }
	std::string getValue() { return _value; }
	
	const int getRank() const {
		std::string rankString = _value.substr(1);
		if (rankString == "J") {
			return 11;
		}
		if (rankString == "Q") {
			return 12;
		}
		if (rankString == "K") {
			return 13;
		}
		if (rankString == "A") {
			return 14;
		}
		return std::stoi(rankString);
	}
	
	bool operator< (const Card &other) const {
		return getRank() < other.getRank();
	}
	
	bool operator> (const Card &other) const {
		return getRank() > other.getRank();
	}
	
	bool operator== (const Card &other) const {
		return getRank() == other.getRank();
	}}
;

std::vector<Card> CardsFromString(std::string hand);


#endif /* Card_hpp */
