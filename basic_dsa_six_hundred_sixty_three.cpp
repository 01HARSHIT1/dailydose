/**
 * Basic DSA - Minimum Right Shifts to Sort the Array (LeetCode 2855)
 * A right-shiftable sorted array has exactly one "drop"; the shift count is n - dropIndex (0 if none).
 */
#include <iostream>
#include <vector>

int minimumRightShifts(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int breaks = 0;
    int pivot = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[static_cast<size_t>(i)] > nums[static_cast<size_t>((i + 1) % n)]) {
            ++breaks;
            pivot = (i + 1) % n;
        }
    }
    if (breaks <= 1)
        return (n - pivot) % n;
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Right Shifts to Sort the Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumRightShifts({3, 4, 5, 1, 2}) << "\n";
    std::cout << "sample 2 -> " << minimumRightShifts({1, 3, 5}) << "\n";
    std::cout << "sample 3 -> " << minimumRightShifts({2, 1, 4}) << "\n";
}
