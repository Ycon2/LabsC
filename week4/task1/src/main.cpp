#include <iostream>
#include <fstream>
#include <string>

class FileReader {
private:
    std::string filename;

public:
    FileReader(const std::string& fname) : filename(fname) {}

    bool open() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
        return true;
    }
};

int main() {
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    FileReader reader(filename);
    if (!reader.open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
    }

    return 0;
}

