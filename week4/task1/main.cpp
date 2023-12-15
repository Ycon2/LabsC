#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Ошибка открытия файла" << std::endl;
    }

    return 0;
}

