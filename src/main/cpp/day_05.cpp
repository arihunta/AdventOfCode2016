#include <fstream>
#include <algorithm>

#include "app.h"
#include "md5.h"

namespace AdventOfCode2016 {

    std::string _05_01() {

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

    std::string _05_02() {

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

}
