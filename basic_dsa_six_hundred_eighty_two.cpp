/**
 * Basic DSA - The Two Sneaky Numbers of Digitville (LeetCode 3289)
 * Numbers 0..n-1 each appear once except two that appear twice; find the two duplicates.
 */
#include <iostream>
#include <vector>

std::vector<int> getSneakyNumbers(const std::vector<int>& nums) {
    std::vector<int> seen(nums.size(), 0);
    std::vector<int> result;
    for (int v : nums) {
        if (++seen[static_cast<size_t>(v)] == 2)
            result.push_back(v);
    }
    return result;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: The Two Sneaky Numbers of Digitville\n";
    std::cout << std::string(60, '=') << "\n";

    auto a = getSneakyNumbers({0, 1, 1, 0});
    std::cout << "sample 1 -> " << a[0] << ", " << a[1] << "\n";

    auto b = getSneakyNumbers({0, 3, 2, 1, 3, 2});
    std::cout << "sample 2 -> " << b[0] << ", " << b[1] << "\n";
}
