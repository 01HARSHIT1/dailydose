/**
 * Basic DSA - Advantage Shuffle (LeetCode 870)
 * Permute nums1 to maximize count where perm[i] > nums2[i]. Sort nums1; process nums2 indices from largest B: use biggest unused A if it wins, else discard smallest A.
 */
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

std::vector<int> advantageCount(std::vector<int> nums1, const std::vector<int>& nums2) {
    int n = static_cast<int>(nums1.size());
    std::vector<std::pair<int, int>> order;
    order.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i)
        order.push_back({nums2[static_cast<size_t>(i)], i});
    std::sort(order.begin(), order.end());
    std::sort(nums1.begin(), nums1.end());

    std::vector<int> res(static_cast<size_t>(n));
    int lo = 0;
    int hi = n - 1;
    for (int k = n - 1; k >= 0; --k) {
        int idx = order[static_cast<size_t>(k)].second;
        int b = order[static_cast<size_t>(k)].first;
        if (nums1[static_cast<size_t>(hi)] > b)
            res[static_cast<size_t>(idx)] = nums1[static_cast<size_t>(hi--)];
        else
            res[static_cast<size_t>(idx)] = nums1[static_cast<size_t>(lo++)];
    }
    return res;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Advantage Shuffle\n";
    std::cout << std::string(60, '=') << "\n";

    auto out = advantageCount({2, 7, 11, 15}, {1, 10, 4, 11});
    std::cout << "perm: ";
    for (size_t i = 0; i < out.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << out[i];
    }
    std::cout << "\n";
}
