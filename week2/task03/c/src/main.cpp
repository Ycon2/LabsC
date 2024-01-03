#include <iostream>
#include <algorithm>

class Array {
private:
    int* arr;
    int size;

    void sort() {
        std::sort(arr, arr + size);
    }

public:
    Array(int n) : size(n) {
        arr = new int[n];
    }

    ~Array() {
        delete[] arr;
    }

    void readElements() {
        std::cout << "Введите элементы массива: ";
        for (int i = 0; i < size; ++i) {
            std::cin >> arr[i];
        }
    }

    double findMedian() {
        sort();

        if (size % 2 == 0) {
            return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
        } else {
            return arr[size / 2];
        }
    }
};

int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    Array nums(n);
    nums.readElements();

    double median = nums.findMedian();
    std::cout << "Медиана массива: " << median << std::endl;

    return 0;
}
