#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string sentence;

    std::cout << "Введите строку: ";
    std::getline(std::cin, sentence);

    std::regex regex("(\\w)\\1{2,}");

    std::cout << "Результат: " << std::regex_replace(sentence, regex, "$1") << std::endl;

    return 0;
}
