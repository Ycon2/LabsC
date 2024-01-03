#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

const int MAX_SENSOR_ID = 99;

class Sensor {
    int id;
    double sumTemperatures;
    int readingsCount;

public:
    Sensor() : id(0), sumTemperatures(0), readingsCount(0) {}

    void addReading(double temperature) {
        sumTemperatures += temperature;
        readingsCount++;
    }

    double averageTemperature() const {
        if (readingsCount == 0) return 0;
        return sumTemperatures / readingsCount;
    }

    bool hasReadings() const {
        return readingsCount > 0;
    }

    int getId() const {
        return id;
    }

    void setId(int newId) {
        id = newId;
    }
};

class SensorNetwork {
private:
    Sensor sensors[MAX_SENSOR_ID + 1];

public:
    void addSensorData(int id, double temperature) {
        sensors[id].setId(id);
        sensors[id].addReading(temperature);
    }

    void displaySorted(int sortField) const {
        if (sortField == 1) {
            for (const Sensor& sensor : sensors) {
                if (sensor.hasReadings()) {
                    std::cout << std::setw(2) << std::setfill('0') << sensor.getId() << " "
                              << std::fixed << std::setprecision(1)
                              << sensor.averageTemperature() << std::endl;
                }
            }
        } else if (sortField == 2) {
            for (double temp = -50.0; temp <= 50.0; temp += 0.1) {
                for (const Sensor& sensor : sensors) {
                    if (sensor.hasReadings()) {
                        double averageTemperature = sensor.averageTemperature();
                        if (std::abs(averageTemperature - temp) < 0.05) {
                            std::cout << std::setw(2) << std::setfill('0') << sensor.getId() << " "
                                      << std::fixed << std::setprecision(1)
                                      << averageTemperature << std::endl;
                        }
                    }
                }
            }
        } else {
            std::cout << "Неверный выбор поля для сортировки." << std::endl;
        }
    }
};

void calculateAverageTemperatures(const std::string &packet, SensorNetwork &network) {
    std::istringstream iss(packet);
    std::string data;

    while (std::getline(iss, data, '@')) {
        if (data.length() > 2) {
            int id = std::stoi(data.substr(0, 2));
            double temperature = std::stod(data.substr(2));
            network.addSensorData(id, temperature);
        }
    }
}

int main() {
    std::string packet;
    std::cout << "Введите пакет показаний: ";
    std::getline(std::cin, packet);

    SensorNetwork network;
    calculateAverageTemperatures(packet, network);

    int sortField;
    std::cout << "Введите поле для сортировки (1 - id, 2 - средняя температура): ";
    std::cin >> sortField;
    network.displaySorted(sortField);

    return 0;
}
