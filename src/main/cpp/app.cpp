#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>

#include "app.h"
#include "md5.h"

int AdventOfCode2016::Answers::_01_01() {

    int axis[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int direction = 0;
    int coords[2] = {0, 0};

    std::string input("R3, L5, R2, L1, L2, R5, L2, R2, L2, L2, L1, R2, L2, R4, R4, R1, L2, L3, R3, L1, R2, L2, L4, R4, R5, L3, R3, L3, L3, R4, R5, L3, R3, L5, L1, L2, R2, L1, R3, R1, L1, R187, L1, R2, R47, L5, L1, L2, R4, R3, L3, R3, R4, R1, R3, L1, L4, L1, R2, L1, R4, R5, L1, R77, L5, L4, R3, L2, R4, R5, R5, L2, L2, R2, R5, L2, R194, R5, L2, R4, L5, L4, L2, R5, L3, L2, L5, R5, R2, L3, R3, R1, L4, R2, L1, R5, L1, R5, L1, L1, R3, L1, R5, R2, R5, R5, L4, L5, L5, L5, R3, L2, L5, L4, R3, R1, R1, R4, L2, L4, R5, R5, R4, L2, L2, R5, R5, L5, L2, R4, R4, L4, R1, L3, R1, L1, L1, L1, L4, R5, R4, L4, L4, R5, R3, L2, L2, R3, R1, R4, L3, R1, L4, R3, L3, L2, R2, R2, R2, L1, L4, R3, R2, R2, L3, R2, L3, L2, R4, L2, R3, L4, R5, R4, R1, R5, R3");

    input = std::regex_replace(input, std::regex(", "), "\n");

    std::stringstream in_stream(input);

    std::string token;

    while (std::getline(in_stream, token)) {

        if (token[0] == 'L') {
            direction = direction == 3 ? 0 : direction + 1;
        }
        else {
            direction = direction == 0 ? 3 : direction - 1;
        }

        token = token.substr(1);

        int steps = atoi(token.c_str());
        coords[0] += steps * axis[direction][0];
        coords[1] += steps * axis[direction][1];

    }

    return abs(coords[0]) + abs(coords[1]);

}

int AdventOfCode2016::Answers::_01_02() {

    int axis[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int direction = 0;
    int coords[2] = {0, 0};

    std::unordered_set<std::string> visited;

    std::string input("R3, L5, R2, L1, L2, R5, L2, R2, L2, L2, L1, R2, L2, R4, R4, R1, L2, L3, R3, L1, R2, L2, L4, R4, R5, L3, R3, L3, L3, R4, R5, L3, R3, L5, L1, L2, R2, L1, R3, R1, L1, R187, L1, R2, R47, L5, L1, L2, R4, R3, L3, R3, R4, R1, R3, L1, L4, L1, R2, L1, R4, R5, L1, R77, L5, L4, R3, L2, R4, R5, R5, L2, L2, R2, R5, L2, R194, R5, L2, R4, L5, L4, L2, R5, L3, L2, L5, R5, R2, L3, R3, R1, L4, R2, L1, R5, L1, R5, L1, L1, R3, L1, R5, R2, R5, R5, L4, L5, L5, L5, R3, L2, L5, L4, R3, R1, R1, R4, L2, L4, R5, R5, R4, L2, L2, R5, R5, L5, L2, R4, R4, L4, R1, L3, R1, L1, L1, L1, L4, R5, R4, L4, L4, R5, R3, L2, L2, R3, R1, R4, L3, R1, L4, R3, L3, L2, R2, R2, R2, L1, L4, R3, R2, R2, L3, R2, L3, L2, R4, L2, R3, L4, R5, R4, R1, R5, R3");

    input = std::regex_replace(input, std::regex(", "), "\n");

    std::stringstream in_stream(input);

    std::string token;

    while (std::getline(in_stream, token)) {

        if (token[0] == 'L') {
            direction = direction == 3 ? 0 : direction + 1;
        }
        else {
            direction = direction == 0 ? 3 : direction - 1;
        }

        token = token.substr(1);

        int steps = atoi(token.c_str());
        for (int i = 0; i < steps; i++) {
            coords[0] += axis[direction][0];
            coords[1] += axis[direction][1];
            std::string stroords = std::to_string(coords[0]) + "," + std::to_string(coords[1]);
            if (visited.find(stroords) != visited.end()) {
                return abs(coords[0]) + abs(coords[1]);
            }
            else {
                visited.insert(stroords);
            }
        }


    }

    return -1;

}

int AdventOfCode2016::Answers::_02_01() {

    std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/02", std::ios::in);

    int numbers[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int code = 0;
    int coords[2] = {1, 1};

    if (in.is_open()) {
        std::string line;
        while (getline(in, line)) {
            for (char& character : line) {
                switch (character) {
                    case 'U':
                        coords[1] = std::max(coords[1] - 1, 0);
                        break;
                    case 'D':
                        coords[1] = std::min(coords[1] + 1, 2);
                        break;
                    case 'R':
                        coords[0] = std::min(coords[0] + 1, 2);
                        break;
                    case 'L':
                        coords[0] = std::max(coords[0] - 1, 0);
                        break;
                }
            }
            code = code * 10 + numbers[coords[1]][coords[0]];
        }
    }

    return code;

}

std::string AdventOfCode2016::Answers::_02_02() {

    std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/02", std::ios::in);

    char numbers[7][7] = {
        {'0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '0', '0', '0'},
        {'0', '0', '2', '3', '4', '0', '0'},
        {'0', '5', '6', '7', '8', '9', '0'},
        {'0', '0', 'A', 'B', 'C', '0', '0'},
        {'0', '0', '0', 'D', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0'},
    };
    std::string code = "";
    int coords[2] = {3, 3};

    if (in.is_open()) {
        std::string line;
        while (getline(in, line)) {
            for (char& character : line) {
                switch (character) {
                    case 'U':
                        coords[1] = numbers[coords[1] - 1][coords[0]] == '0' ? coords[1] : coords[1] - 1;
                        break;
                    case 'D':
                        coords[1] = numbers[coords[1] + 1][coords[0]] == '0' ? coords[1] : coords[1] + 1;
                        break;
                    case 'R':
                        coords[0] = numbers[coords[1]][coords[0] + 1] == '0' ? coords[0] : coords[0] + 1;
                        break;
                    case 'L':
                        coords[0] = numbers[coords[1]][coords[0] - 1] == '0' ? coords[0] : coords[0] - 1;
                        break;
                }
            }
            code = code + numbers[coords[1]][coords[0]];
        }
    }

    return code;

}

int AdventOfCode2016::Answers::_03_01() {

    std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/03", std::ios::in);

    int validCount = 0;

    if (in.is_open()) {
        while (!in.eof()) {
            std::vector<int> sides(3);
            in >> std::ws >> sides[0] >> std::ws;
            in >> std::ws >> sides[1] >> std::ws;
            in >> std::ws >> sides[2] >> std::ws;
            std::sort(sides.begin(), sides.end());
            if (sides[2] < (sides[0] + sides[1])) validCount++;
        }
    }

    return validCount;

}

int AdventOfCode2016::Answers::_03_02() {

    std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/03", std::ios::in);

    int validCount = 0;

    if (in.is_open()) {
        while (!in.eof()) {

            std::vector<std::vector<int>> triangles(3);
            triangles[0] = std::vector<int>(3);
            triangles[1] = std::vector<int>(3);
            triangles[2] = std::vector<int>(3);

            for (int i = 0; i < 3; i++) {
                in >> std::ws >> triangles[0][i] >> std::ws;
                in >> std::ws >> triangles[1][i] >> std::ws;
                in >> std::ws >> triangles[2][i] >> std::ws;
            }

            for (int i = 0; i < 3; i++) {
                std::sort(triangles[i].begin(), triangles[i].end());
                if (triangles[i][2] < (triangles[i][0] + triangles[i][1])) validCount++;
            }
        }
    }

    return validCount;

}

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

int AdventOfCode2016::Answers::_04_01() {

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

int AdventOfCode2016::Answers::_04_02() {

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

std::string AdventOfCode2016::Answers::_05_01() {

    std::string input = "cxdnnyjw";
    std::string password = "";
    int idx = 0;

    while (password.length() < 8) {

        auto test = input + std::to_string(idx);

        MD5 md5;
        md5.update(test.c_str(), test.length());
        md5.finalize();
        auto hash = md5.hexdigest();

        if (hash.find("00000") == 0) {
            password = password + hash[5];
        }

        idx++;

    }

    return password;

}

std::string AdventOfCode2016::Answers::_05_02() {

    std::string input = "cxdnnyjw";
    std::string password = "--------";
    int idx = 0;
    int kount = 0;

    while (kount < 8) {

        auto test = input + std::to_string(idx);

        MD5 md5;
        md5.update(test.c_str(), test.length());
        md5.finalize();
        auto hash = md5.hexdigest();

        if (hash.find("00000") == 0) {
            int index = hash[5] - 48;
            if (index >= 0 && index < 8 && password[index] == '-'){
                password[index] = hash[6];
                kount++;
            }
        }

        idx++;

    }

    return password;

}

std::string AdventOfCode2016::Answers::_06_01() {

    std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/06", std::ios::in);

    int frequencies[8][26] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    if (in.is_open()) {
        std::string line;
        while (getline(in, line)) {
            for (int i = 0; i < 8; i++) {
                frequencies[i][line[i] - 97]++;
            }
        }
    }

    std::string message = "";

    for (int i = 0; i < 8; i++) {
        int maxFreq = 0;
        char maxChar = '-';
        for (int j = 0; j < 26; j++) {
            if (frequencies[i][j] > maxFreq) {
                maxFreq = frequencies[i][j];
                maxChar = (char)(j + 97);
            }
        }
        message = message + maxChar;
    }

    return message;

}

std::string AdventOfCode2016::Answers::_06_02() {

    std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/06", std::ios::in);

    int frequencies[8][26] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    if (in.is_open()) {
        std::string line;
        while (getline(in, line)) {
            for (int i = 0; i < 8; i++) {
                frequencies[i][line[i] - 97]++;
            }
        }
    }

    std::string message = "";

    for (int i = 0; i < 8; i++) {
        int minFreq = -1;
        char minChar = '-';
        for (int j = 0; j < 26; j++) {
            if (minFreq == -1 || frequencies[i][j] < minFreq) {
                minFreq = frequencies[i][j];
                minChar = (char)(j + 97);
            }
        }
        message = message + minChar;
    }

    return message;

}

int AdventOfCode2016::Answers::_07_01() {

    std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/07", std::ios::in);
    int validCount = 0;

    if (in.is_open()) {
        std::string line;
        while (getline(in, line)) {
            bool isInBrackets = false;
            bool isNotValid = false;
            bool isValid = false;
            for (int i = 0; i < line.length() - 3; i++) {
                switch (line[i]) {
                    case '[':
                        isInBrackets = true;
                        break;
                    case ']':
                        isInBrackets = false;
                        break;
                    default: {
                        if (
                            line[i] == line[i + 3]
                            && line[i + 1] == line[i + 2]
                            && line[i] != line[i + 1]
                        ) {
                            if (isInBrackets) {
                                isNotValid = true;
                            }
                            else {
                                isValid = true;
                            }
                        }
                    }
                }
            }
            if (isValid && !isNotValid) {
                validCount++;
            }
        }
    }

    return validCount;

}

int AdventOfCode2016::Answers::_07_02() {

    std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/07", std::ios::in);
    int validCount = 0;

    if (in.is_open()) {
        std::string line;
        while (getline(in, line)) {
            bool isValid = false;
            bool isInBrackets = false;
            std::set<std::string> hypernets;
            std::set<std::string> supernets;
            for (int i = 0; i < line.length() - 2; i++) {
                switch (line[i]) {
                    case '[':
                        isInBrackets = true;
                        break;
                    case ']':
                        isInBrackets = false;
                        break;
                    default: {
                        if (
                            line[i] == line[i + 2]
                            && line[i] != line[i + 1]
                        ) {
                            std::string straight = std::to_string(line[i]) + std::to_string(line[i + 1]) + std::to_string(line[i]);
                            std::string reverse = std::to_string(line[i + 1]) + std::to_string(line[i]) + std::to_string(line[i + 1]);
                            if (isInBrackets) {
                                if (supernets.find(reverse) != supernets.end()) {
                                    isValid = true;
                                }
                                else {
                                    hypernets.insert(straight);
                                }
                            }
                            else {
                                if (hypernets.find(reverse) != hypernets.end()) {
                                    isValid = true;
                                }
                                else {
                                    supernets.insert(straight);
                                }
                            }
                        }
                    }
                }
            }
            if (isValid) {
                validCount++;
            }
        }
    }

    return validCount;

}

int main () {
    return 0;
}
