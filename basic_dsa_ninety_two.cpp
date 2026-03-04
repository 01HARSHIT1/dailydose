/**
 * Basic DSA - Shuffle the Array (LeetCode 1470)
 * Shuffle [x1,x2,...,xn,y1,y2,...,yn] to [x1,y1,x2,y2,...,xn,yn].
 */
#include <iostream>
#include <vector>

std::vector<int> shuffle(std::vector<int>& nums, int n) {
    std::vector<int> out(2 * n);
    for (int i = 0; i < n; i++) {
        out[2 * i] = nums[i];
        out[2 * i + 1] = nums[n + i];
    }
    return out;
}

void print(std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Shuffle the Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {2, 5, 1, 3, 4, 7};
    auto r1 = shuffle(a1, 3);
    std::cout << "[2,5,1,3,4,7], n=3 -> ";
    print(r1);

    std::vector<int> a2 = {1, 2, 3, 4, 4, 3, 2, 1};
    auto r2 = shuffle(a2, 4);
    std::cout << "[1,2,3,4,4,3,2,1], n=4 -> ";
    print(r2);
}
