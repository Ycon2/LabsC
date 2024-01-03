#include <iostream>
#include <cmath>

int main() {
    double edgeLength; // длина ребра икосаэдра

    // Ввод длины ребра
    std::cout << "Введите длину ребра икосаэдра: ";
    std::cin >> edgeLength;

    // Вычисление объема икосаэдра
    double volume = (5.0 / 12.0) * (3 + sqrt(5)) * pow(edgeLength, 3);

    // Вывод результата
    std::cout << "Объем икосаэдра с длиной ребра " << edgeLength << " равен: " << volume << std::endl;

    return 0;
}
