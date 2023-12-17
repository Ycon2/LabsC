# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.27.8)

# Указываем название проекта
project(task1)

# Указываем исходные файлы
set(EXECUTABLE_OUTPUT_PATH bin)

# Добавляем исполняемый файл
add_executable(task.exe main.cpp)

add_library(chrono chrono.h)

set_target_properties(chrono PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(task.exe PUBLIC chrono)
# Указываем путь к заголовочному файлу
target_include_directories(task.exe PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/")

