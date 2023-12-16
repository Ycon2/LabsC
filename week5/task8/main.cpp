#include <iostream>
#include <set>
#include <vector>

int main() {
    int num_students;
    std::cin >> num_students;

    // Множество языков, которые знают все школьники
    std::set<std::string> languages_all;

    // Множество языков, которые знает хотя бы один школьник
    std::set<std::string> languages_any;

    for (int i = 0; i < num_students; i++) {
        int num_languages;
        std::cin >> num_languages;

        // Множество языков для текущего школьника
        std::set<std::string> languages_student;

        for (int j = 0; j < num_languages; j++) {
            std::string language;
            std::cin >> language;
            languages_student.insert(language);
        }

        if (i == 0) {
            languages_all = languages_student;  // Инициализируем множество языков для первого школьника
        } else {
            // Находим пересечение множеств языков всех школьников
            std::set<std::string> intersection;
            for (const std::string& lang : languages_student) {
                if (languages_all.count(lang)) {
                    intersection.insert(lang);
                }
            }
            languages_all = intersection;
        }

        // Объединяем множество языков всех школьников
        languages_any.insert(languages_student.begin(), languages_student.end());
    }

    // Выводим количество языков, которые знают все школьники
    std::cout << "Вывод" << std::endl;
    std::cout << languages_all.size() << std::endl;
    for (const std::string& lang : languages_all) {
        std::cout << lang << std::endl;
    }

    // Выводим количество языков, которые знает хотя бы один школьник
    std::cout << languages_any.size() << std::endl;
    for (const std::string& lang : languages_any) {
        std::cout << lang << std::endl;
    }

    return 0;
}
