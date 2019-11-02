#include <fstream>
#include <vector>
#include <map>
#include <regex>
#include <algorithm>

#include "app.h"

namespace AdventOfCode2016 {

    std::string getChecksum(std::string value) {

        std::map<char, int> letterCounts;

        for (auto letter : value) {
            auto idx = letterCounts.find(letter);
            if (idx == letterCounts.end()) {
                letterCounts.insert(std::pair<char, int>(letter, 1));
            }
            else {
                idx->second = idx->second++;
            }
        }

        std::map<int, std::vector<char>> countsOfLetters;
        for (auto it = letterCounts.begin(); it != letterCounts.end(); it++) {
            auto findResult = countsOfLetters.find(it->second);
            if (findResult == countsOfLetters.end()) {
                std::vector<char> letters;
                letters.push_back(it->first);
                countsOfLetters.insert(std::pair<int, std::vector<char>>(it->second, letters));
            }
            else {
                findResult->second.push_back(it->first);
            }
        }

        std::string checksum = "";
        auto it = countsOfLetters.end();
        for (; it != countsOfLetters.begin() && checksum.length() < 5;) {
            it--;
            std::sort(it->second.begin(), it->second.end());
            for (auto it2 = it->second.begin(); it2 != it->second.end() && checksum.length() < 5; it2++)
                checksum = checksum + *it2;
        }

        return checksum;

    }

    int _04_01() {

        std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/04", std::ios::in);
        std::regex lineMatcher("(([a-z]+-)+)([0-9]+)\\[(\\w\\w\\w\\w\\w)\\]", std::regex_constants::ECMAScript);

        int validCount = 0;

        if (in.is_open()) {
            std::string line;
            while (getline(in, line)) {
                std::smatch match;
                std::regex_search(line, match, lineMatcher);
                auto vals = std::regex_replace(match.str(1), std::regex("-"), "");
                auto id = atoi(match.str(3).c_str());
                auto checksum = match.str(4);
                if (checksum == getChecksum(vals))
                    validCount += id;
            }

        }

        return validCount;

    }

    int _04_02() {

        std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/04", std::ios::in);
        std::regex lineMatcher("(([a-z]+-)+)([0-9]+)\\[(\\w\\w\\w\\w\\w)\\]", std::regex_constants::ECMAScript);

        int validCount = 0;

        std::string chrs = "abcdefghijklmnopqrstuvwxyz";

        if (in.is_open()) {
            std::string line;
            while (getline(in, line)) {
                std::smatch match;
                std::regex_search(line, match, lineMatcher);
                auto vals = match.str(1);
                auto id = atoi(match.str(3).c_str());
                auto checksum = match.str(4);
                if (checksum == getChecksum(std::regex_replace(match.str(1), std::regex("-"), ""))){
                    std::string decoded = "";
                    for (char chr : vals) {
                        if (chr == '-')
                            decoded = decoded + " ";
                        else
                            decoded = decoded + (char) (97 + (id + ((int)chr) - 97) % 26);
                    }
                    if (decoded == "northpole object storage ") return id;
                }
            }

        }

        return 0;

    }

}