#include <iostream>
using namespace std;

double sqrtUsingHeron(double num) {
    if (num < 0) {
        cout << "Ошибка: введено отрицательное число!" << endl;
        return -1;
    }

    double x0 = num; // начальное приближение
    double x1 = (x0 + num / x0) / 2; // первое приближение

    while (abs(x1 - x0) > 0.00001) { // разница между текущим и предыдущим приближением
        x0 = x1;
        x1 = (x0 + num / x0) / 2;
    }

    return x1;
}

int main() {
    double num;
    cout << "Введите число: ";
    cin >> num;

    double sqrtValue = sqrtUsingHeron(num);
    if (sqrtValue != -1) {
        cout << "Квадратный корень из " << num << " = " << sqrtValue << endl;
    }

    return 0;
}
