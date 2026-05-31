/**
 * Basic DSA - Select K Disjoint Special Substrings (LeetCode 3458)
 * Check if k non-overlapping special substrings can be chosen from s.
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

bool canSelect(const std::string& s, int k) {
    if (k == 0)
        return true;

    const int n = static_cast<int>(s.size());
    std::vector<int> first(26, -1);
    std::vector<int> last(26, -1);

    for (int i = 0; i < n; ++i) {
        const int c = s[i] - 'a';
        if (first[c] == -1)
            first[c] = i;
        last[c] = i;
    }

    std::vector<std::pair<int, int>> intervals;
    for (int i = 0; i < n; ++i) {
        if (i != first[s[i] - 'a'])
            continue;

        int x = i + 1;
        int j = last[s[i] - 'a'];
        for (; x <= j && first[s[x] - 'a'] >= i; ++x)
            j = std::max(j, last[s[x] - 'a']);

        if (x == j + 1 && (i != 0 || j != n - 1))
            intervals.push_back({i, j});
    }

    std::sort(intervals.begin(), intervals.end(),
              [](const auto& a, const auto& b) { return a.second < b.second; });

    int overlaps = 0;
    int right = INT_MIN;
    for (const auto& interval : intervals) {
        if (interval.first <= right)
            ++overlaps;
        else
            right = interval.second;
    }

    return static_cast<int>(intervals.size()) - overlaps >= k;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Select K Disjoint Special Substrings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << canSelect("abcdbaefab", 2) << "\n";
    std::cout << "sample 2 -> " << canSelect("cdefdc", 3) << "\n";
    std::cout << "sample 3 -> " << canSelect("abeabe", 0) << "\n";
}
