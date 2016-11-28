#ifndef StringHelper_hpp
#define StringHelper_hpp

#include <string>
#include <vector>

namespace StringHelper {
	unsigned long split(const std::string &txt, std::vector<std::string> &strs, char separator = ' ');
}

#endif /* StringHelper_hpp */
