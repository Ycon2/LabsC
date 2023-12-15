#include <iostream>
#include <string>

using namespace std;

int main() {
    string message;
    int choice;

    cout << "Введите сообщение: ";
    getline(cin, message);

    cout << "Выберите тип преобразования:" << endl;
    cout << "1. В верхний регистр" << endl;
    cout << "2. В нижний регистр" << endl;
    cout << "3. В целочисленное значение" << endl;
    cout << "4. В дробное значение" << endl;
    cin >> choice;

    switch (choice) {
        case 1: {
            for (int i = 0; i < message.length(); i++) {
                message[i] = toupper(message[i]);
            }
            cout << "Результат: " << message << endl;
            break;
        }
        case 2: {
            for (int i = 0; i < message.length(); i++) {
                message[i] = tolower(message[i]);
            }
            cout << "Результат: " << message << endl;
            break;
        }
        case 3: {
            try {
                int num = stoi(message);
                cout << "Результат: " << num << endl;
            } catch (invalid_argument& e) {
                cout << "Ошибка: невозможно преобразовать в целое число." << endl;
            }
            break;
        }
        case 4: {
            try {
                float num = stof(message);
                cout << "Результат: " << num << endl;
            } catch (invalid_argument& e) {
                cout << "Ошибка: невозможно преобразовать в дробное число." << endl;
            }
            break;
        }
        default:
            cout << "Ошибка: неверный выбор." << endl;
            break;
    }

    return 0;
}
