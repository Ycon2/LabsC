#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {
    std::ifstream file("input.txt");
    std::map<std::string, std::map<std::string, int>> sales_database;
    std::string buyer, product;
    int quantity;

    while (file >> buyer >> product >> quantity) {
        sales_database[buyer][product] += quantity;
    }

    for (const auto &buyer_record : sales_database) {

        std::cout << buyer_record.first << ":\n";

        for (const auto &product_record : buyer_record.second) {
            std::cout << product_record.first << " " << product_record.second << '\n';
        }
    }

    return 0;
}
