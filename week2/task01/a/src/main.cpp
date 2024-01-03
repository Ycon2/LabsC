#include <iostream>
#include <string>

class Age {
private:
    int value;
    std::string yearsText;

    void calculateYearsText() {
        int lastDigit = value % 10;

        if ((value >= 11 && value <= 14) || lastDigit == 0 || lastDigit >= 5) {
            yearsText = "лет";
        } else if (lastDigit == 1) {
            yearsText = "год";
        } else if (lastDigit >= 2 && lastDigit <= 4) {
            yearsText = "года";
        }
    }

public:
    Age(int initialValue) {
        setValue(initialValue);
    }

    void setValue(int newValue) {
        value = newValue;
        calculateYearsText();
    }

    int getValue() {
        return value;
    }

    std::string getYearsText() {
        return yearsText;
    }
};

int main() {
    int ageValue;
    std::cout << "Введите возраст: ";
    std::cin >> ageValue;

    Age age(ageValue);

    std::cout << "Ваш возраст: " << age.getValue() << " " << age.getYearsText() << std::endl;

    return 0;
}
