/**
 * Basic DSA - Partition Array into Two Equal Product Subsets (LeetCode 3566)
 * Binary enumeration over subset splits; both products must equal target.
 */

#include <iostream>
#include <vector>

bool canPartitionEqualProduct(const std::vector<int>& values, long long targetProduct) {
    const int count = static_cast<int>(values.size());
    const int maskLimit = 1 << count;

    for (int mask = 1; mask < maskLimit - 1; ++mask) {
        long long firstProduct = 1;
        long long secondProduct = 1;

        for (int index = 0; index < count; ++index) {
            if ((mask >> index) & 1)
                firstProduct *= values[index];
            else
                secondProduct *= values[index];

            if (firstProduct > targetProduct || secondProduct > targetProduct)
                break;
        }

        if (firstProduct == targetProduct && secondProduct == targetProduct)
            return true;
    }

    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Partition Array into Two Equal Product Subsets\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> "
              << canPartitionEqualProduct({3, 1, 6, 8, 4}, 24) << "\n";
    std::cout << "sample 2 -> "
              << canPartitionEqualProduct({2, 5, 3, 7}, 15) << "\n";
}
