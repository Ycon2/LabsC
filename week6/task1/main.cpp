#include <iostream>
#include <unordered_map>

std::pair<char, int> findMostFrequentChar(const std::string& s) {
    std::unordered_map<char, int> charCount;
    char mostFrequentChar = '\0';
    int maxCount = 0;

    for (char c : s) {
        charCount[c]++;
        if (charCount[c] > maxCount) {
            mostFrequentChar = c;
            maxCount = charCount[c];
        }
    }

    return std::make_pair(mostFrequentChar, maxCount);
}

int main() {
    std::string s;
    std::cout << "Введите строку: ";
    std::getline(std::cin, s);

    std::pair<char, int> result = findMostFrequentChar(s);
    std::cout << "Самый часто встречающийся символ: " << result.first << std::endl;
    std::cout << "Количество повторений: " << result.second << std::endl;

    return 0;
}
