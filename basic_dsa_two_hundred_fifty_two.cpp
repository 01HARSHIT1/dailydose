/**
 * Basic DSA - Height Checker (LeetCode 1051)
 * Return number of indices where heights[i] != expected[i].
 */
#include <iostream>
#include <vector>
#include <algorithm>

int heightChecker(std::vector<int>& heights) {
    std::vector<int> expected = heights;
    std::sort(expected.begin(), expected.end());
    int cnt = 0;
    for (int i = 0; i < (int)heights.size(); i++)
        if (heights[i] != expected[i]) cnt++;
    return cnt;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Height Checker\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 1, 4, 2, 1, 3};
    std::cout << "[1,1,4,2,1,3] -> " << heightChecker(v1) << "\n";

    std::vector<int> v2 = {5, 1, 2, 3, 4};
    std::cout << "[5,1,2,3,4] -> " << heightChecker(v2) << "\n";

    std::vector<int> v3 = {1, 2, 3, 4, 5};
    std::cout << "[1,2,3,4,5] -> " << heightChecker(v3) << "\n";
}
