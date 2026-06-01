/**
 * Basic DSA - Unique 3-Digit Even Numbers (LeetCode 3483)
 * Enumerate distinct 3-digit even numbers with no leading zero.
 */

#include <iostream>
#include <unordered_set>
#include <vector>

int totalNumbers(const std::vector<int>& digits) {
    std::unordered_set<int> numbers;
    const int n = static_cast<int>(digits.size());

    for (int hundredsIndex = 0; hundredsIndex < n; ++hundredsIndex) {
        if (digits[hundredsIndex] % 2 == 1)
            continue;

        for (int tensIndex = 0; tensIndex < n; ++tensIndex) {
            if (tensIndex == hundredsIndex)
                continue;

            for (int onesIndex = 0; onesIndex < n; ++onesIndex) {
                if (onesIndex == hundredsIndex || onesIndex == tensIndex)
                    continue;
                if (digits[onesIndex] == 0)
                    continue;

                numbers.insert(digits[onesIndex] * 100 + digits[tensIndex] * 10 +
                               digits[hundredsIndex]);
            }
        }
    }

    return static_cast<int>(numbers.size());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Unique 3-Digit Even Numbers\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << totalNumbers({1, 2, 3, 4}) << "\n";
    std::cout << "sample 2 -> " << totalNumbers({0, 2, 2}) << "\n";
    std::cout << "sample 3 -> " << totalNumbers({6, 6, 6}) << "\n";
    std::cout << "sample 4 -> " << totalNumbers({1, 3, 5}) << "\n";
}
