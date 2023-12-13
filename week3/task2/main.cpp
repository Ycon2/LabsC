#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

double calculateEntropy(const std::string& str) {
    std::string alphabet = "";
    for (char c : str) {
        if (alphabet.find(c) == std::string::npos) {
            alphabet += c;
        }
    }

    int length = str.length();
    double entropy = 0.0;

    for (char c : alphabet) {
        int count = 0;
        for (char ch : str) {
            if (ch == c) {
                count++;
            }
        }
        double probability = static_cast<double>(count) / length;
        entropy -= probability * log2(probability);
    }

    return entropy;
}

int main() {
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    double entropy = calculateEntropy(str);
    std::cout << "Энтропия: " << std::fixed << std::setprecision(2) << entropy << std::endl;

    return 0;
}
