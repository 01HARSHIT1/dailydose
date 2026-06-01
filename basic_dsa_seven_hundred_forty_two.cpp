/**
 * Basic DSA - Lexicographically Smallest Generated String (LeetCode 3474)
 * Build smallest string where T/F flags force or forbid str2 at each offset.
 */

#include <iostream>
#include <string>
#include <vector>

std::string generateString(const std::string& str1, const std::string& str2) {
    const int n = static_cast<int>(str1.size());
    const int m = static_cast<int>(str2.size());
    std::string ans(n + m - 1, 'a');
    std::vector<bool> fixed(n + m - 1, false);

    for (int i = 0; i < n; ++i) {
        if (str1[i] != 'T')
            continue;
        for (int j = 0; j < m; ++j) {
            const int k = i + j;
            if (fixed[k] && ans[k] != str2[j])
                return "";
            ans[k] = str2[j];
            fixed[k] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (str1[i] != 'F')
            continue;

        bool same = true;
        for (int j = 0; j < m; ++j) {
            if (ans[i + j] != str2[j]) {
                same = false;
                break;
            }
        }
        if (!same)
            continue;

        bool changed = false;
        for (int j = i + m - 1; j >= i; --j) {
            if (!fixed[j]) {
                ans[j] = 'b';
                changed = true;
                break;
            }
        }
        if (!changed)
            return "";
    }

    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Lexicographically Smallest Generated String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << generateString("TFTF", "ab") << "\n";
    std::cout << "sample 2 -> " << generateString("TFTF", "abc") << "\n";
    std::cout << "sample 3 -> " << generateString("F", "d") << "\n";
}
