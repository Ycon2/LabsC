#include "headers/task03b.h"

int main() {
    Application app;
    std::map<std::string, std::vector<std::string>> result = app.run();
    std::cout << result["commonLanguages"].size() << std::endl;
    printVector(result["commonLanguages"]);
    std::cout << result["uniqueLanguages"].size() << std::endl;
    printVector(result["uniqueLanguages"]);
    return 0;
}
