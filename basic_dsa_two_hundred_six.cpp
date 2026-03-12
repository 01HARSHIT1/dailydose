/**
 * Basic DSA - 3Sum (LeetCode 15)
 * Find all unique triplets that sum to zero.
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> out;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int lo = i + 1, hi = n - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum == 0) {
                out.push_back({nums[i], nums[lo], nums[hi]});
                while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                lo++; hi--;
            } else if (sum < 0) lo++;
            else hi--;
        }
    }
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: 3Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {-1, 0, 1, 2, -1, -4};
    auto r1 = threeSum(a1);
    std::cout << "[-1,0,1,2,-1,-4] -> ";
    for (const auto& t : r1) std::cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    std::cout << "\n";

    std::vector<int> a2 = {0, 1, 1};
    auto r2 = threeSum(a2);
    std::cout << "[0,1,1] -> (none)\n";
}
