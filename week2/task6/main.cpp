#include <iostream>
#include <vector>

void sieveOfEratosthenes(int n) {
    std::vector<bool> prime(n+1, true); // Создаем вектор для хранения простых чисел, изначально все числа считаем простыми

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            // Если число p является простым, помечаем все его кратные как составные числа
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Выводим все простые числа
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            std::cout << p << " ";
    }
}

int main() {
    int n;
    std::cout << "Введите верхнюю границу диапазона: ";
    std::cin >> n;

    std::cout << "Простые числа в диапазоне от 2 до " << n << ":\n";
    sieveOfEratosthenes(n);

    return 0;
}
