#include <fstream>
#include <algorithm>

#include "app.h"

namespace AdventOfCode2016 {

    std::string _06_01() {

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

    std::string _06_02() {

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

}
