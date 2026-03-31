/**
 * Basic DSA - Keyboard Row (LeetCode 500)
 * Return words that can be typed using letters from only one keyboard row.
 */
#include <iostream>
#include <string>
#include <vector>

bool allInRow(const std::string& w, const std::string& row) {
    for (char c : w) {
        if (row.find(c) == std::string::npos)
            return false;
    }
    return true;
}

std::vector<std::string> findWords(const std::vector<std::string>& words) {
    const std::string top = "qwertyuiopQWERTYUIOP";
    const std::string mid = "asdfghjklASDFGHJKL";
    const std::string bot = "zxcvbnmZXCVBNM";
    std::vector<std::string> ans;
    for (const std::string& w : words) {
        if (allInRow(w, top) || allInRow(w, mid) || allInRow(w, bot))
            ans.push_back(w);
    }
    return ans;
}

void printStrVec(const std::vector<std::string>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << "\"" << v[i] << "\"";
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Keyboard Row\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::string> w1 = {"Hello", "Alaska", "Dad", "Peace"};
    printStrVec(w1);
    std::cout << " -> ";
    printStrVec(findWords(w1));
    std::cout << "\n";

    std::vector<std::string> w2 = {"omk"};
    printStrVec(w2);
    std::cout << " -> ";
    printStrVec(findWords(w2));
    std::cout << "\n";

    std::vector<std::string> w3 = {"adsdf", "sfd"};
    printStrVec(w3);
    std::cout << " -> ";
    printStrVec(findWords(w3));
    std::cout << "\n";
}
