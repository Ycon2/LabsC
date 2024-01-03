#include <iostream>
#include <cmath>

class HeronSqrtCalculator {
private:
    double number;

public:
    HeronSqrtCalculator(double num) : number(num) {
        if (num < 0) {
            throw std::invalid_argument("Ошибка: введено отрицательное число!");
        }
    }

    double calculate() {
        double x0 = number;
        double x1 = (x0 + number / x0) / 2;

        while (std::abs(x1 - x0) > 0.00001) {
            x0 = x1;
            x1 = (x0 + number / x0) / 2;
        }

        return x1;
    }
};

int main() {
    std::cout << "Введите число: ";
    double num;
    std::cin >> num;

    try {
        HeronSqrtCalculator calculator(num);
        double sqrtValue = calculator.calculate();
        std::cout << "Квадратный корень из " << num << " = " << sqrtValue << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
