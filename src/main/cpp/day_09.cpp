#include <fstream>
#include <algorithm>
#include <regex>

#include "app.h"

namespace AdventOfCode2016 {

    int _09_01() {

        std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/09", std::ios::in);

        std::regex multiplier("\\((\\d+)x(\\d+)\\)", std::regex_constants::ECMAScript);
        std::string line;

        if (in.is_open() && getline(in, line)) {

            int totalHeaderSize = 0;
            int decompressionSize = 0;

            std::smatch match;
            std::regex_search(line, match, multiplier);

            int lastPosition = 0;

            for (auto it = std::sregex_iterator(line.begin(), line.end(), multiplier); it != std::sregex_iterator(); ++it) {
                if (it->position() < lastPosition) continue;
                auto headerSize = (*it).str(0).length();
                auto numLetters = atoi((*it).str(1).c_str());
                auto multiplier = atoi((*it).str(2).c_str());
                auto sum = numLetters * (multiplier - 1);
                lastPosition = it->position() + headerSize + numLetters;
                totalHeaderSize += headerSize;
                decompressionSize += sum;
            }

            return line.length() - totalHeaderSize + decompressionSize;

        }

        return -1;

    }

    std::regex multiplier("\\((\\d+)x(\\d+)\\)", std::regex_constants::ECMAScript);

    unsigned long long decompress(std::string str) {

        unsigned long long stringLength = str.length();

        std::smatch match;
        std::regex_search(str, match, multiplier);

        int lastPosition = 0;

        for (auto it = std::sregex_iterator(str.begin(), str.end(), multiplier); it != std::sregex_iterator(); ++it) {

            // skip over this if it's inside an already-decompressed string
            if (it->position() < lastPosition) continue;

            auto headerSize = (*it).str(0).length();
            auto numLetters = atoi((*it).str(1).c_str());
            auto multiplier = atoi((*it).str(2).c_str());
            auto subString = str.substr(it->position() + headerSize, numLetters);
            lastPosition = it->position() + headerSize + numLetters;

            stringLength += multiplier * decompress(subString) - headerSize - numLetters;

        }

        return stringLength;

    }

    unsigned long long _09_02() {

        std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/09", std::ios::in);
        std::string line;

        if (in.is_open() && getline(in, line)) {

            return decompress(line);

        }

        return -1;

    }

}
