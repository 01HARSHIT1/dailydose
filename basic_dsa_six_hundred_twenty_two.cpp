/**
 * Basic DSA - Merge Two 2D Arrays by Summing Values (LeetCode 2570)
 * Both arrays sorted by id; two-pointer merge, summing values where ids match.
 */
#include <iostream>
#include <vector>

std::vector<std::vector<int>> mergeArrays(const std::vector<std::vector<int>>& nums1,
                                          const std::vector<std::vector<int>>& nums2) {
    std::vector<std::vector<int>> result;
    size_t i = 0;
    size_t j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i][0] == nums2[j][0]) {
            result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
            ++i;
            ++j;
        } else if (nums1[i][0] < nums2[j][0]) {
            result.push_back(nums1[i]);
            ++i;
        } else {
            result.push_back(nums2[j]);
            ++j;
        }
    }
    while (i < nums1.size())
        result.push_back(nums1[i++]);
    while (j < nums2.size())
        result.push_back(nums2[j++]);
    return result;
}

void printPairs(const std::vector<std::vector<int>>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << "[" << v[i][0] << "," << v[i][1] << "]";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Merge Two 2D Arrays by Summing Values\n";
    std::cout << std::string(60, '=') << "\n";

    printPairs(mergeArrays({{1, 2}, {2, 3}, {4, 5}}, {{1, 4}, {3, 2}, {4, 1}}));
    printPairs(mergeArrays({{2, 4}, {3, 6}, {5, 5}}, {{1, 3}, {4, 3}}));
}
