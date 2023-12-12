#include <iostream>
#include <vector>
#include <algorithm>

double findMedian(std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());

    if (n % 2 == 0) {
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    } else {
        return nums[n / 2];
    }
}

int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    double median = findMedian(nums);
    std::cout << "Медиана массива: " << median << std::endl;

    return 0;
}
