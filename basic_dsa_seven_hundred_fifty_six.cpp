/**
 * Basic DSA - Phone Number Prefix (LeetCode 3491)
 * Return false if any phone number is a prefix of another after sorting.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool phonePrefix(std::vector<std::string> numbers) {
    std::sort(numbers.begin(), numbers.end());

    for (int i = 1; i < static_cast<int>(numbers.size()); ++i) {
        const std::string& previous = numbers[i - 1];
        const std::string& current = numbers[i];

        if (current.size() >= previous.size() &&
            current.compare(0, previous.size(), previous) == 0)
            return false;
    }

    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Phone Number Prefix\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << phonePrefix({"1", "2", "4", "3"}) << "\n";
    std::cout << "sample 2 -> " << phonePrefix({"001", "007", "15", "00153"}) << "\n";
}
