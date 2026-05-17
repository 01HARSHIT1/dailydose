/**
 * Basic DSA - Snapshot Array (LeetCode 1146)
 * Each index keeps a time-stamped value log (snap id). `set` updates at current snap; `snap` bumps id; `get` binary-searches latest entry at or before a snap.
 */
#include <iostream>
#include <utility>
#include <vector>

struct SnapshotArray {
    int curSnap = 0;
    std::vector<std::vector<std::pair<int, int>>> hist;

    explicit SnapshotArray(int length) : hist(static_cast<size_t>(length)) {}

    void set(int index, int val) {
        auto& v = hist[static_cast<size_t>(index)];
        if (!v.empty() && v.back().first == curSnap)
            v.back().second = val;
        else
            v.push_back({curSnap, val});
    }

    int snap() { return curSnap++; }

    int get(int index, int snap_id) const {
        const auto& v = hist[static_cast<size_t>(index)];
        int lo = 0;
        int hi = static_cast<int>(v.size()) - 1;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[static_cast<size_t>(mid)].first <= snap_id) {
                ans = v[static_cast<size_t>(mid)].second;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        return ans;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Snapshot Array\n";
    std::cout << std::string(60, '=') << "\n";

    SnapshotArray sa(3);
    sa.set(0, 5);
    std::cout << "snap -> " << sa.snap() << "\n";
    sa.set(0, 6);
    std::cout << "get(0,0) -> " << sa.get(0, 0) << " (expect 5)\n";
    std::cout << "snap -> " << sa.snap() << "\n";
    std::cout << "get(0,1) -> " << sa.get(0, 1) << " (expect 6)\n";
}
