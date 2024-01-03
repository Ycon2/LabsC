#include <iostream>
#include <regex>
#include <string>

class RegexProcessor {
private:
    std::regex regex;
public:
    RegexProcessor(const std::string& regexPattern) : regex(regexPattern) {}

    std::string process(const std::string& input) {
        return std::regex_replace(input, regex, "$1");
    }
};

int main() {
    std::string sentence;
    std::cout << "Введите строку: ";
    std::getline(std::cin, sentence);

    RegexProcessor processor("(\\w)\\1{2,}");

    std::cout << "Результат: " << processor.process(sentence) << std::endl;

    return 0;
}
