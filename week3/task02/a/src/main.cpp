#include <iostream>
#include <regex>
#include <string>

class EmailValidator {
private:
    std::regex emailRegex;

public:
    EmailValidator() : emailRegex(R"([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,})") {}

    bool isValid(const std::string& email) const {
        return std::regex_match(email, emailRegex);
    }
};

int main() {
    EmailValidator validator; // Создаем объект класса EmailValidator

    std::string email;
    std::cout << "Введите адрес электронной почты: ";
    std::cin >> email;

    // Используем метод isValid для проверки введенной строки
    if (validator.isValid(email)) {
        std::cout << "Введенная строка является адресом электронной почты." << std::endl;
    } else {
        std::cout << "Введенная строка не является адресом электронной почты." << std::endl;
    }

    return 0;
}
