#ifndef APP_H
#define APP_H

#include <chrono> // подключаем заголовочный файл библиотеки chrono

// создаем пространство имен chrono, чтобы не писать std::chrono каждый раз
namespace chrono = std::chrono;

// создаем синонимы для часто используемых типов длительностей
using seconds = chrono::duration<double>;
using milliseconds = chrono::duration<double, std::milli>;
using microseconds = chrono::duration<double, std::micro>;
using nanoseconds = chrono::duration<double, std::nano>;

// создаем синонимы для часто используемых типов точек времени
using system_time_point = chrono::time_point<chrono::system_clock>;
using steady_time_point = chrono::time_point<chrono::steady_clock>;
using high_resolution_time_point = chrono::time_point<chrono::high_resolution_clock>;

#endif // CHRONO_H
