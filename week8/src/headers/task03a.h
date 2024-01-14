#include <iostream>
#include <set>

class App {
public:
    void processString(std::string& userInput, std::set<int>& result) {
        if (userInput.find(",") == std::string::npos) {
            result.insert(std::stoi(userInput.substr(0, userInput.back())));
        } else {
            result.insert(std::stoi(userInput.substr(0, userInput.find(",")+1)));
        }
        userInput.erase(0, userInput.find(",")+1);
        return;
    }

    std::set<int> run(std::string& userInput) {
        std::set<int> result;
        while (userInput.find(",") != std::string::npos) {
            processString(userInput, result);
        }
        processString(userInput, result);
        return result;
    }
};
