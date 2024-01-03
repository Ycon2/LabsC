#include <iostream>
#include <limits>

int main() {
    // Вывод максимальных и минимальных значений числовых типов данных

    // Целочисленные типы данных
    std::cout << "Максимальное значение типа int: " << 
std::numeric_limits<int>::max() << std::endl;
    std::cout << "Минимальное значение типа int: " << 
std::numeric_limits<int>::min() << std::endl;

    std::cout << "Максимальное значение типа unsigned int: " << 
std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "Минимальное значение типа unsigned int: " << 
std::numeric_limits<unsigned int>::min() << std::endl;

    std::cout << "Максимальное значение типа short: " << 
std::numeric_limits<short>::max() << std::endl;
    std::cout << "Минимальное значение типа short: " << 
std::numeric_limits<short>::min() << std::endl;

    std::cout << "Максимальное значение типа unsigned short: " << 
std::numeric_limits<unsigned short>::max() << std::endl;
    std::cout << "Минимальное значение типа unsigned short: " << 
std::numeric_limits<unsigned short>::min() << std::endl;

    std::cout << "Максимальное значение типа long: " << 
std::numeric_limits<long>::max() << std::endl;
    std::cout << "Минимальное значение типа long: " << 
std::numeric_limits<long>::min() << std::endl;

    std::cout << "Максимальное значение типа unsigned long: " << 
std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "Минимальное значение типа unsigned long: " << 
std::numeric_limits<unsigned long>::min() << std::endl;

    std::cout << "Максимальное значение типа long long: " << 
std::numeric_limits<long long>::max() << std::endl;
    std::cout << "Минимальное значение типа long long: " << 
std::numeric_limits<long long>::min() << std::endl;

    std::cout << "Максимальное значение типа unsigned long long: " << 
std::numeric_limits<unsigned long long>::max() << std::endl;
    std::cout << "Минимальное значение типа unsigned long long: " << 
std::numeric_limits<unsigned long long>::min() << std::endl;

    // Вещественные типы данных
    std::cout << "Максимальное значение типа float: " << 
std::numeric_limits<float>::max() << std::endl;
    std::cout << "Минимальное значение типа float: " << 
std::numeric_limits<float>::min() << std::endl;

    std::cout << "Максимальное значение типа double: " << 
std::numeric_limits<double>::max() << std::endl;
    std::cout << "Минимальное значение типа double: " << 
std::numeric_limits<double>::min() << std::endl;

    std::cout << "Максимальное значение типа long double: " << 
std::numeric_limits<long double>::max() << std::endl;
    std::cout << "Минимальное значение типа long double: " << 
std::numeric_limits<long double>::min() << std::endl;

    return 0;
}
