#include <iostream>
#include <string>
#include <cctype> // Для функций toupper() и tolower()

using namespace std;

// Класс для преобразования сообщения
class MessageConverter {
private:
    string message;

public:
    void setMessage(const string& msg) {
        message = msg;
    }

    string toUpperCase() {
        string upperMessage = message;
        for (char& ch : upperMessage) {
            ch = toupper(ch);
        }
        return upperMessage;
    }

    string toLowerCase() {
        string lowerMessage = message;
        for (char& ch : lowerMessage) {
            ch = tolower(ch);
        }
        return lowerMessage;
    }

    int toInteger() {
        return stoi(message);
    }

    float toFloat() {
        return stof(message);
    }
};

int main() {
    MessageConverter converter;
    string message;
    int choice;

    cout << "Введите сообщение: ";
    getline(cin, message);
    converter.setMessage(message);

    cout << "Выберите тип преобразования:" << endl;
    cout << "1. В верхний регистр" << endl;
    cout << "2. В нижний регистр" << endl;
    cout << "3. В целочисленное значение" << endl;
    cout << "4. В дробное значение" << endl;
    cin >> choice;

    try {
        switch (choice) {
            case 1:
                cout << "Результат: " << converter.toUpperCase() << endl;
                break;
            case 2:
                cout << "Результат: " << converter.toLowerCase() << endl;
                break;
            case 3:
                cout << "Результат: " << converter.toInteger() << endl;
                break;
            case 4:
                cout << "Результат: " << converter.toFloat() << endl;
                break;
            default:
                cout << "Ошибка: неверный выбор." << endl;
                break;
        }
    } catch (const invalid_argument& e) {
        cout << "Ошибка: невозможно преобразовать строку." << endl;
    } catch (const out_of_range& e) {
        cout << "Ошибка: число выходит за пределы диапазона." << endl;
    }

    return 0;
}
