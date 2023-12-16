#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

// Функция для поиска файлов по названию
std::vector<std::string> findFilesByName(const std::string& directory, const std::string& filename) {
    std::vector<std::string> foundFiles;

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().filename().string() == filename) {
            foundFiles.push_back(entry.path().string());
        }
    }

    return foundFiles;
}

// Функция для поиска файлов по содержимому
std::vector<std::string> findFilesByContent(const std::string& directory, const std::string& content) {
    std::vector<std::string> foundFiles;

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            std::ifstream file(entry.path().string());
            std::string line;
            while (std::getline(file, line)) {
                if (line.find(content) != std::string::npos) {
                    foundFiles.push_back(entry.path().string());
                    break;
                }
            }
        }
    }

    return foundFiles;
}

int main() {
    std::string directory;
    std::string searchOption;

    std::cout << "Введите путь к директории для поиска файлов: ";
    std::getline(std::cin, directory);

    std::cout << "Выберите опцию поиска (1 - по названию, 2 - по содержимому): ";
    std::getline(std::cin, searchOption);

    if (searchOption == "1") {
        std::string filename;
        std::cout << "Введите название файла для поиска: ";
        std::getline(std::cin, filename);

        std::vector<std::string> foundFiles = findFilesByName(directory, filename);

        if (foundFiles.empty()) {
            std::cout << "Файлы с указанным названием не найдены." << std::endl;
        } else {
            std::cout << "Найдены следующие файлы с указанным названием:" << std::endl;
            for (const auto& file : foundFiles) {
                std::cout << file << std::endl;
            }
        }
    } else if (searchOption == "2") {
        std::string content;
        std::cout << "Введите содержимое для поиска: ";
        std::getline(std::cin, content);

        std::vector<std::string> foundFiles = findFilesByContent(directory, content);

        if (foundFiles.empty()) {
            std::cout << "Файлы с указанным содержимым не найдены." << std::endl;
        } else {
            std::cout << "Найдены следующие файлы с указанным содержимым:" << std::endl;
            for (const auto& file : foundFiles) {
                std::cout << file << std::endl;
            }
        }
    } else {
        std::cout << "Некорректная опция поиска." << std::endl;
    }

    return 0;
}
