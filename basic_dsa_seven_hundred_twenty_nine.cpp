/**
 * Basic DSA - Maximum Difference Between Even and Odd Frequency II (LeetCode 3445)
 * Maximize freq(a) - freq(b) in a substring of length >= k (a odd, b even, b > 0).
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

int maxDifference(const std::string& s, int k) {
    const int n = static_cast<int>(s.size());
    const int inf = INT_MAX / 2;
    int ans = -inf;

    for (int a = 0; a < 5; ++a) {
        for (int b = 0; b < 5; ++b) {
            if (a == b)
                continue;

            int curA = 0;
            int curB = 0;
            int preA = 0;
            int preB = 0;
            int t[2][2] = {{inf, inf}, {inf, inf}};
            int left = -1;

            for (int right = 0; right < n; ++right) {
                curA += (s[right] == '0' + a);
                curB += (s[right] == '0' + b);
                while (right - left >= k && curB - preB >= 2) {
                    t[preA & 1][preB & 1] = std::min(t[preA & 1][preB & 1], preA - preB);
                    ++left;
                    preA += (s[left] == '0' + a);
                    preB += (s[left] == '0' + b);
                }
                ans = std::max(ans, curA - curB - t[(curA & 1) ^ 1][curB & 1]);
            }
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Difference Between Even and Odd Frequency II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxDifference("12233", 4) << "\n";
    std::cout << "sample 2 -> " << maxDifference("1122211", 3) << "\n";
    std::cout << "sample 3 -> " << maxDifference("110", 3) << "\n";
}
