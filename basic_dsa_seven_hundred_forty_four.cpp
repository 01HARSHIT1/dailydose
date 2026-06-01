/**
 * Basic DSA - Choose K Elements With Maximum Sum (LeetCode 3478)
 * For each index, sum up to k largest nums2 values where nums1[j] < nums1[i].
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<long long> findMaxSum(const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
    const int n = static_cast<int>(nums1.size());
    std::vector<std::pair<int, int>> indexed(n);

    for (int i = 0; i < n; ++i)
        indexed[i] = {nums1[i], i};

    std::sort(indexed.begin(), indexed.end());

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    long long sum = 0;
    int left = 0;
    std::vector<long long> ans(n);

    for (int right = 0; right < n; ++right) {
        const int value = indexed[right].first;
        const int index = indexed[right].second;

        while (left < right && indexed[left].first < value) {
            const int candidate = nums2[indexed[left].second];
            minHeap.push(candidate);
            sum += candidate;
            if (static_cast<int>(minHeap.size()) > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            ++left;
        }

        ans[index] = sum;
    }

    return ans;
}

void printArray(const std::vector<long long>& values) {
    std::cout << "[";
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        if (i > 0)
            std::cout << ", ";
        std::cout << values[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Choose K Elements With Maximum Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printArray(findMaxSum({4, 2, 1, 5, 3}, {10, 20, 30, 40, 50}, 2));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printArray(findMaxSum({2, 2, 2, 2}, {3, 1, 2, 3}, 1));
    std::cout << "\n";
}
