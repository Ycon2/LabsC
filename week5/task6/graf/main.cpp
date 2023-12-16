#include <iostream>
#include <unordered_map>
#include <chrono>
#include <fstream>
#include <vector>
#include <cmath>

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
    std::ofstream outputFile("fibonacci_timings.txt");

    outputFile << "# n\tClassic Time (ms)\tOptimized Time (ms)\n";

    std::vector<int> values;
    for (int n = 5; n <= 40; n += 5) {
        values.push_back(n);
    }

    for (int n : values) {
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

        outputFile << n << '\t' << duration1.count() << '\t' << duration2.count() << '\n';
    }

    outputFile.close();

    return 0;
}
