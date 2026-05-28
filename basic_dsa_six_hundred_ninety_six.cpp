/**
 * Basic DSA - Count Subarrays of Length Three With a Condition (LeetCode 3392)
 * Count triples where the middle value equals twice the sum of the outer two.
 */
#include <iostream>
#include <vector>

int countSubarrays(const std::vector<int>& nums) {
    int count = 0;
    for (int i = 1; i + 1 < static_cast<int>(nums.size()); ++i) {
        if ((nums[static_cast<size_t>(i - 1)] + nums[static_cast<size_t>(i + 1)]) * 2
            == nums[static_cast<size_t>(i)])
            ++count;
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Subarrays of Length Three With a Condition\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << countSubarrays({1, 2, 1, 4, 1}) << "\n";
    std::cout << "sample 2 -> " << countSubarrays({1, 1, 1}) << "\n";
}
