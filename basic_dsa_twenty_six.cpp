/**
 * Basic DSA - 3Sum (LeetCode 15)
 * Find all unique triplets that sum to zero.
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> out;
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i + 2 < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int lo = i + 1, hi = (int)nums.size() - 1, target = -nums[i];
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum == target) {
                out.push_back({nums[i], nums[lo], nums[hi]});
                while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                lo++; hi--;
            } else if (sum < target) lo++;
            else hi--;
        }
    }
    return out;
}

void print(std::vector<std::vector<int>>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << "[" << v[i][0] << "," << v[i][1] << "," << v[i][2] << "]";
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: 3Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {-1, 0, 1, 2, -1, -4};
    auto r1 = threeSum(a1);
    std::cout << "[-1,0,1,2,-1,-4] -> ";
    print(r1);

    std::vector<int> a2 = {0, 0, 0};
    auto r2 = threeSum(a2);
    std::cout << "[0,0,0] -> ";
    print(r2);
}
