/**
 * Basic DSA - Find Mirror Score of a String (LeetCode 3412)
 * Match each letter with the nearest earlier unmarked mirror using stacks of indices.
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>

long long calculateScore(const std::string& s) {
    long long score = 0;
    std::vector<std::stack<int>> indices(26);

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        int index = s[static_cast<size_t>(i)] - 'a';
        int mirror = 25 - index;
        if (!indices[static_cast<size_t>(mirror)].empty()) {
            score += i - indices[static_cast<size_t>(mirror)].top();
            indices[static_cast<size_t>(mirror)].pop();
        } else {
            indices[static_cast<size_t>(index)].push(i);
        }
    }
    return score;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Mirror Score of a String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << calculateScore("aczzx") << "\n";
    std::cout << "sample 2 -> " << calculateScore("abcdef") << "\n";
}
