#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for (const auto& price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main() {
    int n;
    cout << "Введите количество цен: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Введите цены: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int maxProfitValue = maxProfit(prices);
    cout << "Максимальная прибыль: " << maxProfitValue << endl;

    return 0;
}
