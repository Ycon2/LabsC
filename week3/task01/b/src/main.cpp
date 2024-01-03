#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <unordered_map>

class EntropyCalculator {
private:
    std::unordered_map<char, int> charFrequencies;
    std::string str;
    double entropy;

public:
    EntropyCalculator(const std::string& s) : str(s), entropy(0.0) {
        calculateFrequencies();
        calculateEntropy();
    }

    void calculateFrequencies() {
        for (char c : str) {
            charFrequencies[c]++;
        }
    }

    void calculateEntropy() {
        int length = str.length();
        for (auto const& pair : charFrequencies) {
            double probability = static_cast<double>(pair.second) / length;
            entropy -= probability * log2(probability);
        }
    }

    double getEntropy() const {
        return entropy;
    }
};

int main() {
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    EntropyCalculator calculator(str);
    double entropy = calculator.getEntropy();

    std::cout << "Энтропия: " << std::fixed << std::setprecision(2) << entropy << std::endl;

    return 0;
}
