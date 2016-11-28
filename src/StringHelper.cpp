#include "StringHelper.h"

unsigned long split(const std::string &txt, std::vector<std::string> &strs) {
    char separator = ' ';
    unsigned long pos = txt.find(separator);
    unsigned long initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != std::string::npos) {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(separator, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos));

    return strs.size();
}
