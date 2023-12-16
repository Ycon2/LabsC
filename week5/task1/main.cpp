#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> perms(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    do {
        result.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));

    return result;
}

int main() {
    int n;
    std::cout << "Введите количество чисел: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Введите числа: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::vector<std::vector<int>> permutations = perms(nums);

    std::cout << "Перестановки чисел: \n";
    for (const auto& perm : permutations) {
        for (const auto& num : perm) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
