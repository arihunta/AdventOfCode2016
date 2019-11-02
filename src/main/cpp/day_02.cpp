#include <fstream>
#include <algorithm>

#include "app.h"

namespace AdventOfCode2016 {

    int _02_01() {

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

    std::string _02_02() {

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

}
