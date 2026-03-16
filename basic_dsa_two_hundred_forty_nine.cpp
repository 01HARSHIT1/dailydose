/**
 * Basic DSA - Replace Elements with Greatest Element on Right (LeetCode 1299)
 * Replace each element with the greatest element to its right.
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> replaceElements(std::vector<int>& arr) {
    int n = arr.size(), mx = -1;
    for (int i = n - 1; i >= 0; i--) {
        int cur = arr[i];
        arr[i] = mx;
        mx = std::max(mx, cur);
    }
    return arr;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Replace Elements with Greatest Element on Right\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {17, 18, 5, 4, 6, 1};
    replaceElements(v1);
    std::cout << "[17,18,5,4,6,1] -> [";
    for (int i = 0; i < (int)v1.size(); i++) std::cout << (i ? "," : "") << v1[i];
    std::cout << "]\n";

    std::vector<int> v2 = {400};
    replaceElements(v2);
    std::cout << "[400] -> [" << v2[0] << "]\n";
}
