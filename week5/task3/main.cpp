#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int maxArea = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, area);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}

int main() {
    int n;
    cout << "Введите количество значений: ";
    cin >> n;

    vector<int> height(n);
    cout << "Введите значения: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int maxAreaValue = maxArea(height);
    cout << "Максимвльная площадь: " << maxAreaValue << endl;
    return 0;
}
