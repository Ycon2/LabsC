#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include "order.cpp"
#include "product.cpp"
#include "customer.cpp"

class Application {
public:
    std::vector<Order> initOrders() {
        Customer customer = Customer(1, "Denis", 1);
        Product product1 = Product(1, "Manga", "Default", 50.0);
        Product product2 = Product(2, "Dakimakura", "Default", 1500.0);
        Product product3 = Product(3, "Merch", "Default", 200.0);
        std::set<Product> products;
        products.insert(product1);
        products.insert(product2);
        Order order1 = Order(1, 1580515205, 1580515240, "Ordered", customer, products);

        products.clear();
        products.insert(product1);
        products.insert(product2);
        products.insert(product3);
        Order order2 = Order(2, 1589515205, 1589515240, "Ordered", customer, products);

        std::vector<Order> orders;
        orders.push_back(order1);
        orders.push_back(order2);
        return orders;
    }

    double getSum(const std::vector<Order>& orders, time_t startT, time_t endT) {
        double sum = 0.0;
        for (size_t i = 0; i < orders.size(); i++) {
            if ((orders[i].getOrderDate() > startT) && (orders[i].getOrderDate() < endT)) {
                std::set<Product> products = orders[i].getProducts();
                for (const auto& product: products) {
                    sum += product.getPrice();
                }
            }
        }
        return sum;
    }

    int run() {
        std::vector<Order> orders = initOrders();

        double sum = getSum(orders, 1580515200, 1582934400);
        std::cout << "Общая сумма всех заказов в феврале 2020 года: " << sum << std::endl;
        return 0;
    }
};

int main() {
    Application app;
    return app.run();
}
