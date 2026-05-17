/**
 * Basic DSA - Random Pick with Weight (LeetCode 528)
 * Prefix sums of weights; draw r uniformly from [1, sum] and lower_bound on pref to pick an index.
 */
#include <algorithm>
#include <iostream>
#include <vector>

struct WeightPicker {
    std::vector<int> pref;

    explicit WeightPicker(const std::vector<int>& w) {
        pref.resize(w.size());
        pref[0] = w[0];
        for (size_t i = 1; i < w.size(); ++i)
            pref[i] = pref[i - 1] + w[i];
    }

    /** r is 1-based roll in [1, total weight] */
    int pickIndex(int r) const {
        auto it = std::lower_bound(pref.begin(), pref.end(), r);
        return static_cast<int>(it - pref.begin());
    }

    int total() const { return pref.empty() ? 0 : pref.back(); }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Random Pick with Weight\n";
    std::cout << std::string(60, '=') << "\n";

    WeightPicker wp({1, 3});
    std::cout << "weights [1,3] roll=1 -> idx " << wp.pickIndex(1) << "\n";
    std::cout << "weights [1,3] roll=4 -> idx " << wp.pickIndex(4) << "\n";

    WeightPicker wp2({3, 14, 1, 7});
    std::cout << "weights [3,14,1,7] roll=10 (0-based mass at second bucket) -> idx " << wp2.pickIndex(10)
              << "\n";
}
