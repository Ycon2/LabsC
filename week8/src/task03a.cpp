#include <iostream>
#include <set>
#include "headers/task03a.h"

int main() {
    App application;
    std::string userInput;
    std::cin >> userInput;
    std::set<int> result = application.run(userInput);
    for (auto it = result.begin(); it != result.end(); it++) {
        std::cout << *it << std::endl;
    }
    return 0;
}
