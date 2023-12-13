#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string email;
    std::cout << "Введите адрес электронной почты: ";
    std::cin >> email;

    std::regex emailRegex(R"([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,})");
    if (std::regex_match(email, emailRegex)) {
        std::cout << "Введенная строка является адресом электронной почты." << std::endl;
    } else {
        std::cout << "Введенная строка не является адресом электронной почты." << std::endl;
    }

    return 0;
}
