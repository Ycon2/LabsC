#include <iostream>

// Функция для слияния двух подмассивов
void merge(double arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Создаем временные подмассивы
    double leftArr[n1], rightArr[n2];

    // Копируем данные во временные подмассивы
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    // Слияние временных подмассивов обратно в основной массив
    i = 0; // Индекс первого подмассива
    j = 0; // Индекс второго подмассива
    k = left; // Индекс слияния

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Копирование оставшихся элементов левого подмассива
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Копирование оставшихся элементов правого подмассива
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Функция для рекурсивного сортировки слиянием
void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        // Находим середину
        int middle = left + (right - left) / 2;

        // Рекурсивно сортируем два подмассива
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Слияние двух отсортированных подмассивов
        merge(arr, left, middle, right);
    }
}

int main() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    double data_array[size];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        std::cin >> data_array[i];
    }

    // Сортировка массива с использованием MergeSort
    mergeSort(data_array, 0, size - 1);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << data_array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
