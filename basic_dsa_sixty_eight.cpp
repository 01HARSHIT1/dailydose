/**
 * Basic DSA - Partition Labels (LeetCode 763)
 * Partition string so each letter appears in at most one part.
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> partitionLabels(std::string s) {
    int last[26] = {};
    for (int i = 0; i < (int)s.size(); i++) last[s[i] - 'a'] = i;
    std::vector<int> out;
    int start = 0, end = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        end = std::max(end, last[s[i] - 'a']);
        if (i == end) {
            out.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return out;
}

void print(std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Partition Labels\n";
    std::cout << std::string(60, '=') << "\n";

    std::string s1 = "ababcbacadefegdehijhklij";
    auto r1 = partitionLabels(s1);
    std::cout << "\"ababcbacadefegdehijhklij\" -> ";
    print(r1);

    std::string s2 = "eccbbbbdec";
    auto r2 = partitionLabels(s2);
    std::cout << "\"eccbbbbdec\" -> ";
    print(r2);
}
