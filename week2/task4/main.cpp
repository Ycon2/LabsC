#include <iostream>

int main() {
    int height;
    std::cout << "Введите высоту пирамиды: ";
    std::cin >> height;

    for (int i = 1; i <= height; i++) {
        // Выводим пробелы перед символами пирамиды
        for (int j = 1; j <= height - i; j++) {
            std::cout << " ";
        }

        // Выводим символы пирамиды
        for (int j = 1; j <= 2 * i - 1; j++) {
            std::cout << "*";
        }

        // Переходим на новую строку
        std::cout << std::endl;
    }

    return 0;
}
