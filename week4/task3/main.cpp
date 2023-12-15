#include <iostream>
#include <string>
#include <stdexcept> // Для использования исключений

int main() {
    std::string search;
    std::cout << "Что ищем: ";
    std::getline(std::cin, search);

    if (search.empty()) { // Проверяем на пустую строку
        throw std::invalid_argument("Поисковый запрос не может быть пустым!"); // Генерируем исключение
    }

    std::string input;
    std::cout << "Где ищем: ";
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
