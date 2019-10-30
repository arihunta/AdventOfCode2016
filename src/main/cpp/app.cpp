#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include <unordered_set>
#include <fstream>
#include <algorithm>

#include "app.h"

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

int main () {
    return 0;
}
