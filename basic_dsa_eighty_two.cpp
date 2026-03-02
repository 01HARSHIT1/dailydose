/**
 * Basic DSA - Boats to Save People (LeetCode 881)
 * Min boats to carry everyone; each boat has limit, at most 2 people.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int numRescueBoats(std::vector<int>& people, int limit) {
    std::sort(people.begin(), people.end());
    int i = 0, j = (int)people.size() - 1, boats = 0;
    while (i <= j) {
        if (people[i] + people[j] <= limit) i++;
        j--;
        boats++;
    }
    return boats;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Boats to Save People\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2};
    std::cout << "[1,2], limit=3 -> " << numRescueBoats(a1, 3) << "\n";

    std::vector<int> a2 = {3, 2, 2, 1};
    std::cout << "[3,2,2,1], limit=3 -> " << numRescueBoats(a2, 3) << "\n";

    std::vector<int> a3 = {3, 5, 3, 4};
    std::cout << "[3,5,3,4], limit=5 -> " << numRescueBoats(a3, 5) << "\n";
}
