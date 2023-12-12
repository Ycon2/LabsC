#include <iostream>

const int MAX_SIZE = 100;

int main() {
    double data_array[MAX_SIZE];
    int size;

    std::cout << "Введите размер массива (не более " << MAX_SIZE << "): ";
    std::cin >> size;

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Элемент " << i + 1 << ": ";
        std::cin >> data_array[i];
    }

    double max_value = data_array[0];
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (data_array[i] > max_value) {
            max_value = data_array[i];
            count = 1;
        } else if (data_array[i] == max_value) {
            count++;
        }
    }

    std::cout << "Количество чисел, равных максимальному: " << count << std::endl;

    return 0;
}
