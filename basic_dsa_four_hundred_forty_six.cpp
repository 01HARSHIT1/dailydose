/**
 * Basic DSA - Relative Sort Array (LeetCode 1122)
 * Sort arr1: values appear in the same order as arr2; remaining values ascending.
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> relativeSortArray(std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::unordered_map<int, int> cnt;
    for (int x : arr1)
        ++cnt[x];
    std::vector<int> ans;
    ans.reserve(arr1.size());
    for (int x : arr2) {
        auto it = cnt.find(x);
        if (it != cnt.end()) {
            for (int k = 0; k < it->second; ++k)
                ans.push_back(x);
            cnt.erase(it);
        }
    }
    std::vector<int> rest;
    for (const auto& p : cnt) {
        for (int k = 0; k < p.second; ++k)
            rest.push_back(p.first);
    }
    std::sort(rest.begin(), rest.end());
    ans.insert(ans.end(), rest.begin(), rest.end());
    return ans;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Relative Sort Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    std::vector<int> k1 = {2, 1, 4, 3, 9, 6};
    std::vector<int> r1 = relativeSortArray(a1, k1);
    printVec({2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19});
    std::cout << " | ";
    printVec(k1);
    std::cout << " -> ";
    printVec(r1);
    std::cout << "\n";

    std::vector<int> a2 = {28, 6, 22, 8, 44, 17};
    std::vector<int> k2 = {22, 28, 8, 6};
    printVec(a2);
    std::cout << " | ";
    printVec(k2);
    std::cout << " -> ";
    std::vector<int> r2 = relativeSortArray(a2, k2);
    printVec(r2);
    std::cout << "\n";
}
