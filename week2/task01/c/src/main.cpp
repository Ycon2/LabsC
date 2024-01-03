#include <iostream>
#include <string>

class Weather {
private:
    std::string temperature;
    std::string precipitation;
    std::string wind;
    std::string humidity;

public:
    void setWeatherConditions() {
        std::cout << "Введите температуру (hot/warm/cold): ";
        std::cin >> temperature;

        std::cout << "Введите осадки (clear/cloudy/rain/snow/hail): ";
        std::cin >> precipitation;

        std::cout << "Введите наличие ветра (yes/no): ";
        std::cin >> wind;

        std::cout << "Введите влажность (high/low): ";
        std::cin >> humidity;
    }

    bool isGoodForBadminton() const {
        return temperature == "hot" && precipitation == "clear" && wind == "no" && humidity == "low";
    }
};

class BadmintonGame {
public:
    void playGame() {
        std::string day;
        std::cout << "Введите день недели: ";
        std::cin >> day;
        if (day == "Sunday") {
            Weather todayWeather;
            todayWeather.setWeatherConditions();
            if (todayWeather.isGoodForBadminton()) {
                std::cout << "Да, давайте играть в бадминтон!" << std::endl;
            } else {
                std::cout << "Нет, не будем играть в бадминтон." << std::endl;
            }
        } else {
            std::cout << "Сегодня не воскресенье, не будем играть в бадминтон." << std::endl;
        }
    }
};

int main() {
    BadmintonGame game;
    game.playGame();

    return 0;
}
