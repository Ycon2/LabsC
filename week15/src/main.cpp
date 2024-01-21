#include <iostream>
#include <vector>
#include <string>

template<typename T>
class MergeSort {
private:
    std::vector<T>& arr;

    void merge(int left, int mid, int right) {
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<T> L(n1), R(n2);

        for (i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        i = 0;
        j = 0;
        k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

public:
    MergeSort(std::vector<T>& arr) : arr(arr) {}

    void sort(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            sort(left, mid);
            sort(mid + 1, right);

            merge(left, mid, right);
        }
    }
};

int main() {
    int n;
    std::cout << "Enter the number of elements for each type:\n";
    std::cin >> n;

    std::vector<int> intArr(n);
    std::vector<double> doubleArr(n);
    std::vector<std::string> strArr(n);

    std::cout << "Enter " << n << " integers:\n";
    for (int& i : intArr)
        std::cin >> i;

    std::cout << "Enter " << n << " doubles:\n";
    for (double& d : doubleArr)
        std::cin >> d;

    std::cout << "Enter " << n << " strings:\n";
    for (std::string& s : strArr)
        std::cin >> s;

    MergeSort<int> intSorter(intArr);
    intSorter.sort(0, intArr.size() - 1);

    MergeSort<double> doubleSorter(doubleArr);
    doubleSorter.sort(0, doubleArr.size() - 1);

    MergeSort<std::string> strSorter(strArr);
    strSorter.sort(0, strArr.size() - 1);

    std::cout << "Sorted integers:\n";
    for (int i : intArr)
        std::cout << i << " ";
    std::cout << "\n";

    std::cout << "Sorted doubles:\n";
    for (double i : doubleArr)
        std::cout << i << " ";
    std::cout << "\n";

    std::cout << "Sorted strings:\n";
    for (const auto& str : strArr)
        std::cout << str << " ";
    std::cout << "\n";

    return 0;
}
