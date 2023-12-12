#include <iostream>

int main() {
    int month;

    std::cout << "Введите номер месяца: ";
    std::cin >> month;

    int days;

    switch (month) {
        case 2:
            days = 28; // год не високосный
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;
    }

    std::cout << "Количество дней в месяце: " << days << std::endl;

    return 0;
}
