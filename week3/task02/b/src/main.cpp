#include <iostream>
#include <regex>
#include <string>

class IPv6Validator {
private:
    std::regex ipv6Regex;
public:
    IPv6Validator() : ipv6Regex("^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$") {}

    bool validate(const std::string& ipv6) {
        return std::regex_match(ipv6, ipv6Regex);
    }
};

int main() {
    IPv6Validator validator;
    std::string ipv6;

    std::cout << "Введите адрес IPv6: ";
    std::cin >> ipv6;

    if (validator.validate(ipv6)) {
        std::cout << "Адрес IPv6 введен корректно." << std::endl;
    } else {
        std::cout << "Адрес IPv6 введен некорректно." << std::endl;
    }

    return 0;
}
