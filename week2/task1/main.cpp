#include <iostream>

int main() {
    int age;
    std::cout << "Введите возраст: ";
    std::cin >> age;

    int lastDigit = age % 10;
    std::string yearsText;

    if (age >= 11 && age <= 14) {
        yearsText = "лет";
    } else if (lastDigit == 1) {
        yearsText = "год";
    } else if (lastDigit >= 2 && lastDigit <= 4) {
        yearsText = "года";
    } else {
        yearsText = "лет";
    }

    std::cout << "Ваш возраст: " << age << " " << yearsText << std::endl;

    return 0;
}
