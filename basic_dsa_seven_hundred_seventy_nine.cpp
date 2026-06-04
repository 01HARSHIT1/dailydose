/**
 * Basic DSA - Find the Most Common Response (LeetCode 3527)
 * Count each unique daily response once, then pick the highest-frequency word.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::string findCommonResponse(
    const std::vector<std::vector<std::string>>& responses) {
    std::unordered_map<std::string, int> counts;

    for (const std::vector<std::string>& dayResponses : responses) {
        std::unordered_set<std::string> seenToday;
        for (const std::string& response : dayResponses) {
            if (seenToday.insert(response).second)
                ++counts[response];
        }
    }

    std::string bestResponse = responses[0][0];
    for (const auto& entry : counts) {
        const std::string& response = entry.first;
        const int frequency = entry.second;

        if (counts[bestResponse] < frequency ||
            (counts[bestResponse] == frequency && response < bestResponse)) {
            bestResponse = response;
        }
    }

    return bestResponse;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Most Common Response\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << findCommonResponse({{"good", "ok", "good", "ok"},
                                     {"ok", "bad", "good", "ok", "ok"},
                                     {"good"},
                                     {"bad"}})
              << "\n";

    std::cout << "sample 2 -> "
              << findCommonResponse({{"good", "ok", "good"},
                                     {"ok", "bad"},
                                     {"bad", "notsure"},
                                     {"great", "good"}})
              << "\n";
}
