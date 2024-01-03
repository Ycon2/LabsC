#include <iostream>

class Sieve {
private:
    int n; // Верхняя граница для поиска
    bool* prime; // Динамический массив для определения простых чисел

public:
    Sieve(int n) : n(n) {
        prime = new bool[n+1]; // Выделяем память для массива
        std::fill(prime, prime + n + 1, true); // Заполняем массив значениями true
    }

    ~Sieve() {
        delete[] prime; // Освобождаем память при удалении объекта
    }

    void generatePrimes() {
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }

    void displayPrimes() {
        for (int p = 2; p <= n; p++) {
            if (prime[p])
                std::cout << p << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    int n;
    std::cout << "Введите верхнюю границу диапазона: ";
    std::cin >> n;

    Sieve sieve(n); // Создаем объект sieve класса Sieve
    std::cout << "Простые числа в диапазоне от 2 до " << n << ":\n";
    sieve.generatePrimes(); // Генерируем простые числа
    sieve.displayPrimes(); // Выводим их на экран

    return 0;
}
