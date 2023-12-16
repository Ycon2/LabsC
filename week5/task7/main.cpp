#include <iostream>
#include <set>
#include <vector>

int main() {
    std::vector<int> inputArray;
    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        int num;
        std::cin >> num;
        inputArray.push_back(num);
    }

    std::set<int> uniqueElements;
    for (const auto& element : inputArray) {
        uniqueElements.insert(element);
    }

    std::cout << "Массив без дубликатов: ";
    for (const auto& element : uniqueElements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
