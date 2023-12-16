#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int num_words;
    std::cin >> num_words;
    std::cin.ignore();

    std::map<std::string, std::vector<std::string>> latin_to_english_dict;
    std::string line, english_word, latin_word;

    for (int i = 0; i < num_words; i++) {
        std::getline(std::cin, line);
        size_t sep = line.find('-');
        english_word = line.substr(0, sep - 1);
        std::string latin_rest = line.substr(sep + 2);

        std::istringstream latin_stream(latin_rest);
        while (std::getline(latin_stream, latin_word, ',')) {
            size_t start = latin_word.find_first_not_of(" ");
            latin_word = (start == std::string::npos) ? "" : latin_word.substr(start);

            latin_to_english_dict[latin_word].push_back(english_word);
        }
    }

    std::cout << latin_to_english_dict.size() << std::endl;
    for (const auto &pair : latin_to_english_dict) {
        latin_word = pair.first;
        std::vector<std::string> english_words = pair.second;

        std::sort(english_words.begin(), english_words.end());

        std::cout << latin_word << " - ";
        for (size_t j = 0; j < english_words.size(); ++j) {
            std::cout << english_words[j];
            if (j < english_words.size() - 1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}
