/**
 * Basic DSA - Shuffle the Array (LeetCode 1470)
 * nums = [x1,...,xn, y1,...,yn]; return [x1,y1,x2,y2,...,xn,yn].
 */
#include <iostream>
#include <vector>

std::vector<int> shuffle(const std::vector<int>& nums, int n) {
    std::vector<int> out(nums.size());
    for (int i = 0; i < n; ++i) {
        out[2 * i] = nums[i];
        out[2 * i + 1] = nums[n + i];
    }
    return out;
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
    std::cout << "Problem: Shuffle the Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {2, 5, 1, 3, 4, 7};
    printVec(a1);
    std::cout << ", n=3 -> ";
    printVec(shuffle(a1, 3));
    std::cout << "\n";

    std::vector<int> a2 = {1, 2, 3, 4, 4, 3, 2, 1};
    printVec(a2);
    std::cout << ", n=4 -> ";
    printVec(shuffle(a2, 4));
    std::cout << "\n";
}
