/**
 * Basic DSA - Count Items Matching a Rule (LeetCode 1773)
 * Count items where ruleKey matches ruleValue (type/color/name).
 */
#include <iostream>
#include <vector>
#include <string>

int countMatches(std::vector<std::vector<std::string>>& items,
                 std::string ruleKey, std::string ruleValue) {
    int idx = ruleKey == "type" ? 0 : (ruleKey == "color" ? 1 : 2);
    int count = 0;
    for (auto& item : items) {
        if (item[idx] == ruleValue) count++;
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Items Matching a Rule\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<std::string>> items1 = {
        {"phone","blue","pixel"}, {"computer","silver","lenovo"},
        {"phone","gold","iphone"}
    };
    std::cout << "ruleKey=color, ruleValue=silver -> "
              << countMatches(items1, "color", "silver") << "\n";

    std::vector<std::vector<std::string>> items2 = {
        {"phone","blue","pixel"}, {"computer","silver","phone"},
        {"phone","gold","iphone"}
    };
    std::cout << "ruleKey=type, ruleValue=phone -> "
              << countMatches(items2, "type", "phone") << "\n";
}
