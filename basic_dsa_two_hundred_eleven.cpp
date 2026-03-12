/**
 * Basic DSA - Group Anagrams (LeetCode 49)
 * Group strings that are anagrams of each other.
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> mp;
    for (const auto& s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    std::vector<std::vector<std::string>> out;
    for (auto& p : mp) out.push_back(std::move(p.second));
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Group Anagrams\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::string> a1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto r1 = groupAnagrams(a1);
    std::cout << "[eat,tea,tan,ate,nat,bat] -> ";
    for (const auto& g : r1) {
        std::cout << "[";
        for (size_t i = 0; i < g.size(); i++) std::cout << (i ? "," : "") << g[i];
        std::cout << "] ";
    }
    std::cout << "\n";

    std::vector<std::string> a2 = {""};
    auto r2 = groupAnagrams(a2);
    std::cout << "[\"\"] -> [[]]\n";
}
