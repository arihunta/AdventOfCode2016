#include <fstream>
#include <vector>
#include <algorithm>

#include "app.h"

namespace AdventOfCode2016 {

    int _03_01() {

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

    int _03_02() {

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

}