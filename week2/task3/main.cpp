#include <iostream>
#include <string>

int main() {
    std::string day;
    std::string temperature;
    std::string precipitation;
    std::string wind;
    std::string humidity;

    std::cout << "Введите день недели: ";
    std::cin >> day;

    if (day == "Sunday") {
        std::cout << "Введите температуру (hot/warm/cold): ";
        std::cin >> temperature;

        std::cout << "Введите осадки (clear/cloudy/rain/snow/hail): ";
        std::cin >> precipitation;

        std::cout << "Введите наличие ветра (yes/no): ";
        std::cin >> wind;

        std::cout << "Введите влажность (high/low): ";
        std::cin >> humidity;

        if (temperature == "hot" && precipitation == "clear" && wind == "no" && humidity == 
"low") {
            std::cout << "Да, давайте играть в бадминтон!" << std::endl;
        } else {
            std::cout << "Нет, не будем играть в бадминтон." << std::endl;
        }
    } else {
        std::cout << "Сегодня не воскресенье, не будем играть в бадминтон." << std::endl;
    }

    return 0;
}
