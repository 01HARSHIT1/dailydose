/**
 * Basic DSA - Duplicate Zeros (LeetCode 1089)
 * Duplicate each 0, shifting elements to the right; elements past the end are dropped.
 */
#include <iostream>
#include <string>
#include <vector>

void duplicateZeros(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    int z = 0;
    for (int x : arr) {
        if (x == 0)
            ++z;
    }
    int i = n - 1;
    int j = n + z - 1;
    while (i >= 0) {
        if (arr[i] != 0) {
            if (j < n)
                arr[j] = arr[i];
            --i;
            --j;
        } else {
            if (j < n)
                arr[j] = 0;
            --j;
            if (j < n)
                arr[j] = 0;
            --j;
            --i;
        }
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Duplicate Zeros\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 0, 2, 3, 0, 4, 5, 0};
    duplicateZeros(v1);
    std::cout << "[1,0,2,3,0,4,5,0] -> ";
    for (size_t i = 0; i < v1.size(); ++i)
        std::cout << (i ? "," : "") << v1[i];
    std::cout << "\n";

    std::vector<int> v2 = {1, 2, 3};
    duplicateZeros(v2);
    std::cout << "[1,2,3] -> ";
    for (size_t i = 0; i < v2.size(); ++i)
        std::cout << (i ? "," : "") << v2[i];
    std::cout << "\n";
}
