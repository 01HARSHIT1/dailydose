/**
 * Basic DSA - Kth Largest Element in a Stream (LeetCode 703)
 * Design class to add elements and return kth largest.
 */
#include <iostream>
#include <vector>
#include <queue>

class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int k;
public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        for (int x : nums) add(x);
    }
    int add(int val) {
        pq.push(val);
        if ((int)pq.size() > k) pq.pop();
        return pq.top();
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Kth Largest Element in a Stream\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(3, nums);
    std::cout << "add(3) -> " << obj->add(3) << "\n";
    std::cout << "add(5) -> " << obj->add(5) << "\n";
    std::cout << "add(10) -> " << obj->add(10) << "\n";
    std::cout << "add(9) -> " << obj->add(9) << "\n";
    std::cout << "add(4) -> " << obj->add(4) << "\n";
    delete obj;
}
