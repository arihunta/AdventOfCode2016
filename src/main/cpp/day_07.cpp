#include <fstream>
#include <algorithm>
#include <set>

#include "app.h"

namespace AdventOfCode2016 {

    int _07_01() {

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

    int _07_02() {

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

}
