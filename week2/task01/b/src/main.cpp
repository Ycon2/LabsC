#include <iostream>

using namespace std;

class Month {
private:
    int monthNumber;
public:
    Month(int monthNum) : monthNumber(monthNum) {}

    int getDays() {
        switch (monthNumber) {
            case 2:
                return 28; // год не високосный
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            default:
                return 31;
        }
    }
};

int main() {
    int month;

    cout << "Введите номер месяца: ";
    cin >> month;

    Month currentMonth(month);

    cout << "Количество дней в месяце: " << currentMonth.getDays() << endl;

    return 0;
}
