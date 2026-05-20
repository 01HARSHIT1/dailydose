/**
 * Basic DSA - Minimum Amount of Time to Collect Garbage (LeetCode 2391)
 * Three trucks for M, P, G. Each drives only to the last house containing its type: travel prefix + pickup minutes along the way.
 */
#include <iostream>
#include <string>
#include <vector>

int garbageCollection(const std::vector<std::string>& garbage, const std::vector<int>& travel) {
    int total = 0;
    for (char type : {'M', 'P', 'G'}) {
        int last = -1;
        for (int i = 0; i < static_cast<int>(garbage.size()); ++i) {
            for (char ch : garbage[static_cast<size_t>(i)]) {
                if (ch == type)
                    ++total;
            }
            if (garbage[static_cast<size_t>(i)].find(type) != std::string::npos)
                last = i;
        }
        for (int i = 0; i < last; ++i)
            total += travel[static_cast<size_t>(i)];
    }
    return total;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Amount of Time to Collect Garbage\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << garbageCollection({"G", "P", "GP", "GG"}, {2, 4, 3}) << "\n";
    std::cout << "sample 2 -> " << garbageCollection({"MMM", "PGM", "GP"}, {3, 10}) << "\n";
}
