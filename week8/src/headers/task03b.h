#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

typedef std::vector<std::vector<std::string>> Students;

void printVector(std::vector<std::string> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
    return;
}

class Application {
private:
    Students students;
public:
    void setStudents(Students userInput) {
        students = userInput;
        return;
    }

    Students getStudents() {
        int studentsAmount;
        std::string userInput;
        std::cin >> studentsAmount;
        Students students;
        for (int i = 0; i < studentsAmount; i++) {
            int languageAmount;
            std::cin >> languageAmount;
            std::vector<std::string> temp;
            for (int j = 0; j < languageAmount; j++) {
                std::cin >> userInput;
                temp.push_back(userInput);
                std::cin.clear();
            }
            students.push_back(temp);
        }
        return students;
    }

    std::vector<std::string> getCommonLanguages(Students students) {
        std::vector<std::string> languages;
        std::map<std::string, int> languageCounts;
        for (int i = 0; i < students.size(); i++) {
            for (int j = 0; j < students[i].size(); j++) {
                languageCounts[students[i][j]] += 1;
            }
        }
        for (auto i : languageCounts) {
            if (i.second == students.size()) {
                languages.push_back(i.first);
            }
        }
        std::sort(languages.begin(), languages.end());
        return languages;
    }

    std::vector<std::string> getUniqueLanguages(Students students) {
        std::vector<std::string> languages;
        for (int i = 0; i < students.size(); i++) {
            for (int j = 0; j < students[i].size(); j++) {
                if (std::find(languages.begin(), languages.end(), students[i][j]) != languages.end()) continue;
                languages.push_back(students[i][j]);
            }
        }
        std::sort(languages.begin(), languages.end());
        return languages;
    }

    std::map<std::string, std::vector<std::string>> run() {
        if (students.size() == 0) {
            students = getStudents();
        }

        std::vector<std::string> commonLanguages = getCommonLanguages(students);
        std::vector<std::string> uniqueLanguages = getUniqueLanguages(students);

        std::map<std::string, std::vector<std::string>> result;
        result["commonLanguages"] = commonLanguages;
        result["uniqueLanguages"] = uniqueLanguages;
        return result;
    }
};
