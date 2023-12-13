#include <iostream>
#include <regex>

int main() {
    std::string ipv6;
    std::cout << "Введите адрес IPv6: ";
    std::cin >> ipv6;

    std::regex ipv6Regex("^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$");
    if (std::regex_match(ipv6, ipv6Regex)) {
        std::cout << "Адрес IPv6 введен корректно." << std::endl;
    } else {
        std::cout << "Адрес IPv6 введен некорректно." << std::endl;
    }

    return 0;
}
