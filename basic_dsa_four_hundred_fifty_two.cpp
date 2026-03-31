/**
 * Basic DSA - Can Make Arithmetic Progression From Sequence (LeetCode 1502)
 * Can rearrange elements so consecutive differences are equal?
 */
#include <algorithm>
#include <iostream>
#include <vector>

bool canMakeArithmeticProgression(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    if (arr.size() < 2)
        return true;
    int d = arr[1] - arr[0];
    for (size_t i = 2; i < arr.size(); ++i) {
        if (arr[i] - arr[i - 1] != d)
            return false;
    }
    return true;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Can Make Arithmetic Progression From Sequence\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {3, 5, 1};
    printVec({3, 5, 1});
    std::cout << " -> " << (canMakeArithmeticProgression(a1) ? "true" : "false") << "\n";

    std::vector<int> a2 = {1, 2, 4};
    printVec({1, 2, 4});
    std::cout << " -> " << (canMakeArithmeticProgression(a2) ? "true" : "false") << "\n";
}
