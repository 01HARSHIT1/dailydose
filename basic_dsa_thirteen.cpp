/**
 * Basic DSA - Squares of a Sorted Array (LeetCode 977)
 * Return sorted array of squares from sorted input.
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    int n = (int)nums.size();
    std::vector<int> out(n);
    int i = 0, j = n - 1, k = n - 1;
    while (i <= j) {
        int a = nums[i] * nums[i];
        int b = nums[j] * nums[j];
        if (a >= b) {
            out[k--] = a;
            i++;
        } else {
            out[k--] = b;
            j--;
        }
    }
    return out;
}

void print(std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Squares of a Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {-4, -1, 0, 3, 10};
    auto r1 = sortedSquares(a1);
    std::cout << "[-4,-1,0,3,10] -> ";
    print(r1);

    std::vector<int> a2 = {-7, -3, 2, 3, 11};
    auto r2 = sortedSquares(a2);
    std::cout << "[-7,-3,2,3,11] -> ";
    print(r2);
}
