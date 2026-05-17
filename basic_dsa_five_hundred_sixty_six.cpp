/**
 * Basic DSA - Time Based Key-Value Store (LeetCode 981)
 * Per key, append (timestamp, value) sorted by time. get(key, t) returns latest value with time <= t via binary search.
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

struct TimeMap {
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> data;

    void set(const std::string& key, const std::string& value, int timestamp) {
        data[key].push_back({timestamp, value});
    }

    std::string get(const std::string& key, int timestamp) {
        const auto& vec = data[key];
        if (vec.empty())
            return "";
        int lo = 0;
        int hi = static_cast<int>(vec.size()) - 1;
        int best = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (vec[static_cast<size_t>(mid)].first <= timestamp) {
                best = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        return best < 0 ? "" : vec[static_cast<size_t>(best)].second;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Time Based Key-Value Store\n";
    std::cout << std::string(60, '=') << "\n";

    TimeMap tm;
    tm.set("foo", "bar", 1);
    std::cout << "get foo,1 -> " << tm.get("foo", 1) << "\n";
    tm.set("foo", "bar2", 4);
    std::cout << "get foo,4 -> " << tm.get("foo", 4) << "\n";
    std::cout << "get foo,3 -> " << tm.get("foo", 3) << "\n";
    std::cout << "get missing,5 -> \"" << tm.get("x", 5) << "\"\n";
}
