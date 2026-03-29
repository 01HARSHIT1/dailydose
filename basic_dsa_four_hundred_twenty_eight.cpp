/**
 * Basic DSA - Kids With the Greatest Number of Candies (LeetCode 1431)
 * After giving extraCandies to one kid, can they have (tie for) the maximum?
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<bool> kidsWithCandies(const std::vector<int>& candies, int extraCandies) {
    int mx = *std::max_element(candies.begin(), candies.end());
    std::vector<bool> ans;
    ans.reserve(candies.size());
    for (int c : candies)
        ans.push_back(c + extraCandies >= mx);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Kids With the Greatest Number of Candies\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v = {2, 3, 5, 1, 3};
    auto r = kidsWithCandies(v, 3);
    std::cout << "[2,3,5,1,3], extra=3 -> ";
    for (size_t i = 0; i < r.size(); ++i)
        std::cout << (i ? "," : "") << (r[i] ? "true" : "false");
    std::cout << "\n";
}
