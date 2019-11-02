#include <fstream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <regex>
#include <map>

#include "app.h"

namespace AdventOfCode2016 {

    // It's a bot
    struct Bot {
        std::vector<int> numbers;
        std::string instruction;
        Bot() : instruction("") {}
        bool hasTwoChips() { return numbers.size() == 2; };
        bool hasInstruction() { return instruction != ""; }
    };

    std::regex bot("bot (\\d+) gives low to (bot|output) (\\d+) and high to (bot|output) (\\d+)");

    int updateBotLookingForABot(int number, std::string &instruction, int botId, std::map<int, Bot> &bots) {

        Bot &currentBot = bots[botId];

        if (number != -1)
            currentBot.numbers.push_back(number);
        currentBot.instruction = instruction;

        // std::cout << "updating " << botId << " : " << currentBot.numbers.size() << " : " << currentBot.instruction << std::endl;

        std::sort(currentBot.numbers.begin(), currentBot.numbers.end());

        // this bot is our terminal condition
        if (currentBot.hasTwoChips() && currentBot.numbers[0] == 17 && currentBot.numbers[1] == 61) return botId;

        // this bot is ready, so pass its info on
        if (currentBot.hasTwoChips() && currentBot.hasInstruction()) {
            // std::cout << "ready bot " << botId << " : " << currentBot.lowTarget << " - " << currentBot.highTarget << std::endl;

            auto match = std::smatch();
            std::regex_search(currentBot.instruction, match, bot);
            int botId = std::stoi(match.str(1));
            bool lowType = match.str(2) == "bot";
            int lowId = std::stoi(match.str(3));
            bool highType = match.str(4) == "bot";
            int highId = std::stoi(match.str(5));
            
            if (lowType) {
                Bot &newBot = bots[lowId];
                int retVal = updateBotLookingForABot(currentBot.numbers[0], newBot.instruction, lowId, bots);
                if (retVal != -1) return retVal;
            }
            if (highType) {
                Bot &newBot = bots[highId];
                int retVal = updateBotLookingForABot(currentBot.numbers[1], newBot.instruction, highId, bots);
                if (retVal != -1) return retVal;
            }
        }

        return -1;

    }

    int _10_01() {

        std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/10", std::ios::in);
        std::regex init("value (\\d+) goes to bot (\\d+)");

        std::map<int, Bot> bots;

        if (in.is_open()) {
            std::string line;
            while (getline(in, line)) {

                auto match = std::smatch();

                // it's a bot program
                std::regex_search(line, match, bot);
                if (!match.empty()) {

                    // std::cout << "bot" << std::endl;

                    int botId = std::stoi(match.str(1));
                    bool lowType = match.str(2) == "bot";
                    int lowId = std::stoi(match.str(3));
                    bool highType = match.str(4) == "bot";
                    int highId = std::stoi(match.str(5));

                    Bot &botToUpdate = bots[botId];

                    int retVal = updateBotLookingForABot(-1, line, botId, bots);
                    if (retVal != -1) return retVal;

                    continue;

                }

                // it's an initialiser
                std::regex_search(line, match, init);
                if (!match.empty()) {

                    // std::cout << "init" << std::endl;

                    int value = std::stoi(match.str(1));
                    int botId = std::stoi(match.str(2));

                    Bot &botToUpdate = bots[botId];

                    int retVal = updateBotLookingForABot(value, botToUpdate.instruction, botId, bots);
                    if (retVal != -1) return retVal;

                    continue;

                }

            }

        }

        return -1;

    }

    void updateBot(int number, std::string &instruction, int botId, std::map<int, Bot> &bots, std::vector<int> &outputs) {

        Bot &currentBot = bots[botId];

        if (number != -1)
            currentBot.numbers.push_back(number);
        currentBot.instruction = instruction;

        // std::cout << "updating " << botId << " : " << currentBot.numbers.size() << " : " << currentBot.instruction << std::endl;

        std::sort(currentBot.numbers.begin(), currentBot.numbers.end());

        // this bot is ready, so pass its info on
        if (currentBot.hasTwoChips() && currentBot.hasInstruction()) {
            // std::cout << "ready bot " << botId << " : " << currentBot.lowTarget << " - " << currentBot.highTarget << std::endl;
            
            auto match = std::smatch();
            std::regex_search(currentBot.instruction, match, bot);
            int botId = std::stoi(match.str(1));
            bool lowType = match.str(2) == "bot";
            int lowId = std::stoi(match.str(3));
            bool highType = match.str(4) == "bot";
            int highId = std::stoi(match.str(5));

            if (lowType) {
                Bot &newBot = bots[lowId];
                updateBot(currentBot.numbers[0], newBot.instruction, lowId, bots, outputs);
            }
            else outputs[lowId] = currentBot.numbers[0];
            if (highType) {
                Bot &newBot = bots[highId];
                updateBot(currentBot.numbers[1], newBot.instruction, highId, bots, outputs);
            }
            else outputs[highId] = currentBot.numbers[1];
        }

    }

    int _10_02() {

        std::ifstream in("C:/Users/arihu/workspace/AdventOfCode2016/src/main/resources/10", std::ios::in);

        std::regex bot("bot (\\d+) gives low to (bot|output) (\\d+) and high to (bot|output) (\\d+)");
        std::regex init("value (\\d+) goes to bot (\\d+)");

        std::map<int, Bot> bots;
        std::vector<int> outputs(10);

        if (in.is_open()) {
            std::string line;
            while (getline(in, line)) {

                auto match = std::smatch();

                // it's a bot program
                std::regex_search(line, match, bot);
                if (!match.empty()) {

                    // std::cout << "bot" << std::endl;

                    int botId = std::stoi(match.str(1));
                    bool lowType = match.str(2) == "bot";
                    int lowId = std::stoi(match.str(3));
                    bool highType = match.str(4) == "bot";
                    int highId = std::stoi(match.str(5));

                    Bot &botToUpdate = bots[botId];

                    updateBot(-1, line, botId, bots, outputs);

                    continue;

                }

                // it's an initialiser
                std::regex_search(line, match, init);
                if (!match.empty()) {

                    // std::cout << "init" << std::endl;

                    int value = std::stoi(match.str(1));
                    int botId = std::stoi(match.str(2));

                    Bot &botToUpdate = bots[botId];

                    updateBot(value, botToUpdate.instruction, botId, bots, outputs);

                    continue;

                }

            }

        }

        return outputs[0] * outputs[1] * outputs[2];

    }

}
