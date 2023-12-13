#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

const int MAX_PACKET_LENGTH = 512;
const int MAX_SENSOR_ID = 99;

struct SensorData {
    int id;
    double temperature;
};

void calculateAverageTemperatures(const std::string& packet) {
    double sumTemperatures[MAX_SENSOR_ID + 1] = {0.0};
    int countTemperatures[MAX_SENSOR_ID + 1] = {0};

    std::istringstream iss(packet);
    std::string data;

    while (std::getline(iss, data, '@')) {
        if (data.length() > 2) {
            int id = std::stoi(data.substr(0, 2));
            double temperature = std::stod(data.substr(2));

            sumTemperatures[id] += temperature;
            countTemperatures[id]++;
        }
    }

    std::cout << "Введите поле для сортировки (1 - id, 2 - средняя температура): ";
    int sortField;
    std::cin >> sortField;

    std::cout << "Результат:" << std::endl;

    if (sortField == 1) {
        for (int id = 0; id <= MAX_SENSOR_ID; id++) {
            if (countTemperatures[id] > 0) {
                double averageTemperature = sumTemperatures[id] / countTemperatures[id];
                std::cout << std::setw(2) << std::setfill('0') << id << " " << std::fixed << std::setprecision(1) << 
averageTemperature << std::endl;
            }
        }
    } else if (sortField == 2) {
        for (double temperature = -50.0; temperature <= 50.0; temperature += 0.1) {
            for (int id = 0; id <= MAX_SENSOR_ID; id++) {
                if (countTemperatures[id] > 0) {
                    double averageTemperature = sumTemperatures[id] / countTemperatures[id];
                    if (std::abs(averageTemperature - temperature) < 0.05) {
                        std::cout << std::setw(2) << std::setfill('0') << id << " " << std::fixed << std::setprecision(1) 
<< averageTemperature << std::endl;
                    }
                }
            }
        }
    } else {
        std::cout << "Неверный выбор поля для сортировки." << std::endl;
    }
}

int main() {
    std::string packet;

    std::cout << "Введите пакет показаний: ";
    std::getline(std::cin, packet);

    calculateAverageTemperatures(packet);

    return 0;
}
