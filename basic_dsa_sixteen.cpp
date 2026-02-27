/**
 * Basic DSA - Two Sum II (LeetCode 167)
 * Find two indices in sorted array that sum to target.
 */
#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int i = 0, j = (int)numbers.size() - 1;
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target) return {i + 1, j + 1};
        if (sum < target) i++;
        else j--;
    }
    return {-1, -1};
}

void print(std::vector<int>& v) {
    std::cout << "[" << v[0] << "," << v[1] << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Two Sum II (Input Array Is Sorted)\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {2, 7, 11, 15};
    auto r1 = twoSum(a1, 9);
    std::cout << "[2,7,11,15], 9 -> ";
    print(r1);

    std::vector<int> a2 = {2, 3, 4};
    auto r2 = twoSum(a2, 6);
    std::cout << "[2,3,4], 6 -> ";
    print(r2);

    std::vector<int> a3 = {-1, 0};
    auto r3 = twoSum(a3, -1);
    std::cout << "[-1,0], -1 -> ";
    print(r3);
}
