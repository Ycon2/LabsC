#include "order.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<Order> orders;

    // Заполните список заказов

    double totalAmount = 0.0;

    for (const auto& order : orders) {
        // Получаем дату заказа из объекта Order
        time_t orderDate = order.getOrderDate();

        // Проверяем, что дата заказа попадает в февраль 2020 года
        struct tm* timeinfo;
        timeinfo = localtime(&orderDate);
        if (timeinfo->tm_year == 120 && timeinfo->tm_mon == 1) {  // 120 - 2020, 1 - февраль
            // Суммируем стоимость продуктов в заказе
            for (const auto& product : order.getProducts()) {
                totalAmount += product.getPrice();
            }
        }
    }

    std::cout << "Общая сумма всех заказов в феврале 2020 года: " << totalAmount << std::endl;

    return 0;
}
