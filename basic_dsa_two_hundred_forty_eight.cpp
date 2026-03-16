/**
 * Basic DSA - Valid Mountain Array (LeetCode 941)
 * Return true if array strictly increases then strictly decreases.
 */
#include <iostream>
#include <vector>

bool validMountainArray(std::vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return false;
    int i = 0;
    while (i + 1 < n && arr[i] < arr[i + 1]) i++;
    if (i == 0 || i == n - 1) return false;
    while (i + 1 < n && arr[i] > arr[i + 1]) i++;
    return i == n - 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Mountain Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 1};
    std::cout << "[2,1] -> " << (validMountainArray(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {3, 5, 5};
    std::cout << "[3,5,5] -> " << (validMountainArray(v2) ? "true" : "false") << "\n";

    std::vector<int> v3 = {0, 3, 2, 1};
    std::cout << "[0,3,2,1] -> " << (validMountainArray(v3) ? "true" : "false") << "\n";
}
