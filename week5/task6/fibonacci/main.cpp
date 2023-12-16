#include <iostream>
#include <unordered_map>
#include <chrono>

// Классический алгоритм для вычисления числа Фибоначчи
int fibClassic(int n) {
    if (n <= 1)
        return n;
    return fibClassic(n - 1) + fibClassic(n - 2);
}

// Оптимизированный алгоритм для вычисления числа Фибоначчи с кешированием результатов
int fibOptimized(int n, std::unordered_map<int, int>& cache) {
    if (n <= 1)
        return n;
    if (cache.find(n) != cache.end())
        return cache[n];
    int result = fibOptimized(n - 1, cache) + fibOptimized(n - 2, cache);
    cache[n] = result;
    return result;
}

int main() {
    int n;

    std::cout << "Введите число Фибоначчи для вычисления: ";
    std::cin >> n;

    // Запуск и замер времени выполнения для классического алгоритма
    auto start = std::chrono::high_resolution_clock::now();
    int fib1 = fibClassic(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration1 = end - start;

    // Запуск и замер времени выполнения для оптимизированного алгоритма
    start = std::chrono::high_resolution_clock::now();
    std::unordered_map<int, int> cache;
    int fib2 = fibOptimized(n, cache);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration2 = end - start;

    // Вывод результатов и времени выполнения
    std::cout << "Классический алгоритм: " << fib1 << ", время выполнения: " << duration1.count() << " мс\n";
    std::cout << "Оптимизированный алгоритм: " << fib2 << ", время выполнения: " << duration2.count() << " мс\n";

    return 0;
}
