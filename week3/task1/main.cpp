#include <iostream>
#include <string>

int main() {
    std::string search;
    std::cout << "Что ищем: ";
    std::cin >> search;

    std::string input;
    std::cout << "Где ищем:\n";
    std::cin.ignore(); // Очищаем буфер ввода
    std::getline(std::cin, input);

    int count = 0;
    while (!input.empty()) {
        size_t found = input.find(search);
        while (found != std::string::npos) {
            count++;
            found = input.find(search, found + 1);
        }

        std::getline(std::cin, input);
    }

    std::cout << "Вывод: " << count << std::endl;

    return 0;
}
