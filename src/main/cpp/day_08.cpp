#include <fstream>
#include <algorithm>
#include <regex>
#include <iostream>

#include "app.h"

namespace AdventOfCode2016 {

    int _08_01() {

        std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/08", std::ios::in);

        int frequencies[6][50] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };

        std::regex rect_regex("rect (\\d+)x(\\d+)", std::regex_constants::ECMAScript);
        std::regex col_regex("rotate column x=(\\d+) by (\\d+)", std::regex_constants::ECMAScript);
        std::regex row_regex("rotate row y=(\\d+) by (\\d+)", std::regex_constants::ECMAScript);

        if (in.is_open()) {
            std::string line;
            while (getline(in, line)) {

                std::smatch match;

                std::regex_search(line, match, rect_regex);
                if (!match.empty()) {
                    int a = atoi(match.str(1).c_str());
                    int b = atoi(match.str(2).c_str());
                    for (int i = 0; i < a; i++)
                        for (int j = 0; j < b; j++)
                            frequencies[j][i] = 1;
                    continue;
                }
                std::regex_search(line, match, col_regex);
                if (!match.empty()) {
                    int a = atoi(match.str(1).c_str());
                    int b = atoi(match.str(2).c_str());
                    int tmp[] = {
                        frequencies[0][a],
                        frequencies[1][a],
                        frequencies[2][a],
                        frequencies[3][a],
                        frequencies[4][a],
                        frequencies[5][a]
                    };
                    for (int i = 0; i < 6; i++) {
                        frequencies[(i + b) % 6][a] = tmp[i];
                    }
                    continue;
                }
                std::regex_search(line, match, row_regex);
                if (!match.empty()) {
                    int a = atoi(match.str(1).c_str());
                    int b = atoi(match.str(2).c_str());
                    int tmp[50];
                    std::copy(std::begin(frequencies[a]), std::end(frequencies[a]), std::begin(tmp));
                    for (int i = 0; i < 50; i++) {
                        frequencies[a][(i + b) % 50] = tmp[i];
                    }
                    continue;
                }

            }
        }
        
        int voltage = 0;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 50; j++)
                voltage += frequencies[i][j];

        return voltage;

    }

    std::string _08_02() {

        std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/08", std::ios::in);

        int frequencies[6][50] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };

        std::regex rect_regex("rect (\\d+)x(\\d+)", std::regex_constants::ECMAScript);
        std::regex col_regex("rotate column x=(\\d+) by (\\d+)", std::regex_constants::ECMAScript);
        std::regex row_regex("rotate row y=(\\d+) by (\\d+)", std::regex_constants::ECMAScript);

        if (in.is_open()) {
            std::string line;
            while (getline(in, line)) {

                std::smatch match;

                std::regex_search(line, match, rect_regex);
                if (!match.empty()) {
                    int a = atoi(match.str(1).c_str());
                    int b = atoi(match.str(2).c_str());
                    for (int i = 0; i < a; i++)
                        for (int j = 0; j < b; j++)
                            frequencies[j][i] = 1;
                    continue;
                }
                std::regex_search(line, match, col_regex);
                if (!match.empty()) {
                    int a = atoi(match.str(1).c_str());
                    int b = atoi(match.str(2).c_str());
                    int tmp[] = {
                        frequencies[0][a],
                        frequencies[1][a],
                        frequencies[2][a],
                        frequencies[3][a],
                        frequencies[4][a],
                        frequencies[5][a]
                    };
                    for (int i = 0; i < 6; i++) {
                        frequencies[(i + b) % 6][a] = tmp[i];
                    }
                    continue;
                }
                std::regex_search(line, match, row_regex);
                if (!match.empty()) {
                    int a = atoi(match.str(1).c_str());
                    int b = atoi(match.str(2).c_str());
                    int tmp[50];
                    std::copy(std::begin(frequencies[a]), std::end(frequencies[a]), std::begin(tmp));
                    for (int i = 0; i < 50; i++) {
                        frequencies[a][(i + b) % 50] = tmp[i];
                    }
                    continue;
                }

            }
        }

        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 50; j++) {
                std::cout << (frequencies[i][j] == 1 ? '#' : ' ');
            }
            std::cout << std::endl;
        }
        return "CFLELOYFCS";

    }

}
