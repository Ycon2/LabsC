#include <iostream>
#include <string>

class SubstringFinder {
private:
    std::string search;
    std::string input;
    int count;

public:
    SubstringFinder() : count(0) {}

    void setSearch(const std::string& search) {
        this->search = search;
    }

    void setInput(const std::string& input) {
        this->input = input;
    }

    void findSubstrings() {
        size_t found = input.find(search);
        while (found != std::string::npos) {
            count++;
            found = input.find(search, found + search.length());
        }
    }

    int getCount() const {
        return count;
    }
};

int main() {
    SubstringFinder finder;

    std::string search;
    std::cout << "Что ищем: ";
    std::cin >> search;
    finder.setSearch(search);

    std::string input;
    std::cout << "Где ищем:\n";
    std::cin.ignore();

    while (std::getline(std::cin, input) && !input.empty()) {
        finder.setInput(input);
        finder.findSubstrings();
    }

    std::cout << "Вывод: " << finder.getCount() << std::endl;

    return 0;
}
