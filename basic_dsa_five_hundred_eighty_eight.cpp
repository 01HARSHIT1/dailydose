/**
 * Basic DSA - Design Browser History (LeetCode 1472)
 * Linear history with a cursor; visit truncates forward trail; back/forward move the cursor within bounds.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct BrowserHistory {
    std::vector<std::string> hist;
    int cur = 0;

    explicit BrowserHistory(const std::string& homepage) { hist.push_back(homepage); }

    void visit(const std::string& url) {
        hist.resize(static_cast<size_t>(cur + 1));
        hist.push_back(url);
        cur = static_cast<int>(hist.size()) - 1;
    }

    std::string back(int steps) {
        cur = std::max(0, cur - steps);
        return hist[static_cast<size_t>(cur)];
    }

    std::string forward(int steps) {
        cur = std::min(static_cast<int>(hist.size()) - 1, cur + steps);
        return hist[static_cast<size_t>(cur)];
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Design Browser History\n";
    std::cout << std::string(60, '=') << "\n";

    BrowserHistory b("leetcode.com");
    b.visit("google.com");
    b.visit("facebook.com");
    b.visit("youtube.com");
    std::cout << "back(1)    -> " << b.back(1) << "\n";
    std::cout << "back(1)    -> " << b.back(1) << "\n";
    std::cout << "forward(1) -> " << b.forward(1) << "\n";
    b.visit("linkedin.com");
    std::cout << "forward(2) -> " << b.forward(2) << "\n";
}
