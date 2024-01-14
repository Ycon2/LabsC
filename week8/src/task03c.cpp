#include "headers/task03c.h"


int main() {
    std::string userInput;
    std::cin >> userInput;
    if (isValidBrackets(userInput)) std::cout << "Valid!" << std::endl;
    else std::cout << "Invalid!" << std::endl;
    return 0;
}
