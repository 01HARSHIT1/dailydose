/**
 * Basic DSA - Count the Number of Beautiful Subarrays (LeetCode 2588)
 * A subarray is beautiful iff its XOR is 0; count pairs of equal prefix XORs via a hash map.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

long long beautifulSubarrays(const std::vector<int>& nums) {
    std::unordered_map<int, long long> seen;
    seen[0] = 1;
    int prefix = 0;
    long long count = 0;
    for (int value : nums) {
        prefix ^= value;
        count += seen[prefix];
        ++seen[prefix];
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count the Number of Beautiful Subarrays\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << beautifulSubarrays({4, 3, 1, 2, 4}) << "\n";
    std::cout << "sample 2 -> " << beautifulSubarrays({1, 10, 4}) << "\n";
}
