#include <iostream>
#include <string>

class Pyramid {
private:
    int height;

public:
    Pyramid(int h) : height(h) {} // конструктор для инициализации высоты пирамиды

    void draw() { // функция для рисования пирамиды
        for (int i = 1; i <= height; i++) {
            // Выводим пробелы перед символами пирамиды
            std::cout << std::string(height - i, ' ');

            for (int j = 1; j <= 2 * i - 1; j++) {
                // Если текущий символ соответствует вертикальному центру пирамиды, пробел вместо звездочки
                if (j == i) {
                    std::cout << ' ';
                } else {
                    std::cout << '*';
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int height;
    std::cout << "Введите высоту пирамиды: ";
    std::cin >> height;

    Pyramid pyramid(height + 1);
    pyramid.draw();

    return 0;
}
