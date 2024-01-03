#include <iostream>
#include <string>
#include <stdexcept>

// Класс для выполнения поиска
class SearchEngine {
private:
    std::string searchQuery;
    std::string text;

public:
    // Конструктор для инициализации поискового запроса и текста, в который добавлена обработка исключений
    SearchEngine(const std::string& search, const std::string& text) {
        if (search.empty()) {
            throw std::invalid_argument("Поисковый запрос не может быть пустым!");
        }
        this->searchQuery = search;
        this->text = text;
    }

    // Функция для подсчета количества вхождений searchQuery в текст
    int countOccurrences() const {
        int count = 0;
        size_t found = this->text.find(this->searchQuery);
        while (found != std::string::npos) {
            count++;
            found = this->text.find(this->searchQuery, found + this->searchQuery.length());
        }
        return count;
    }
};

int main() {
    try {
        // Получаем поисковой запрос от пользователя
        std::string search;
        std::cout << "Что ищем: ";
        std::getline(std::cin, search);

        // Получаем текст для поиска от пользователя
        std::string input;
        std::cout << "Где ищем: ";
        std::getline(std::cin, input);

        // Создаем объект класса SearchEngine
        SearchEngine searchEngine(search, input);

        // Выполняем поиск и выводим количество найденных вхождений
        std::cout << "Вывод: " << searchEngine.countOccurrences() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
