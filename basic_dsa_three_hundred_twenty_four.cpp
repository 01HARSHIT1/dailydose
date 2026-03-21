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
    for (std::string& s : strs) {
        std::string k = s;
        std::sort(k.begin(), k.end());
        mp[k].push_back(std::move(s));
    }
    std::vector<std::vector<std::string>> ans;
    for (auto& p : mp) ans.push_back(std::move(p.second));
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Group Anagrams\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto g = groupAnagrams(v);
    std::cout << "6 strings -> " << g.size() << " groups\n";
}
