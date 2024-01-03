#include <iostream>
#include <unordered_map>
#include <string>

// Класс для анализа частоты символов в строке.
class CharFrequencyAnalyzer {
private:
    std::unordered_map<char, int> charCount;
    char mostFrequentChar;
    int maxCount;

public:
    CharFrequencyAnalyzer() : mostFrequentChar('\0'), maxCount(0) {}

    // Функция анализа строки и нахождения самого частого символа.
    void analyze(const std::string& s) {
        for (char c : s) {
            charCount[c]++;
            if (charCount[c] > maxCount) {
                mostFrequentChar = c;
                maxCount = charCount[c];
            }
        }
    }

    // Функция возвращает наиболее часто встречающийся символ и его количество.
    std::pair<char, int> getMostFrequentChar() const {
        return std::make_pair(mostFrequentChar, maxCount);
    }
};

int main() {
    std::string s;
    std::cout << "Введите строку: ";
    std::getline(std::cin, s);

    CharFrequencyAnalyzer analyzer;
    analyzer.analyze(s);

    std::pair<char, int> result = analyzer.getMostFrequentChar();
    std::cout << "Самый часто встречающийся символ: " << result.first << std::endl;
    std::cout << "Количество повторений: " << result.second << std::endl;

    return 0;
}
