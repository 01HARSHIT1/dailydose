/**
 * Basic DSA - Decompress Run-Length Encoded List (LeetCode 1313)
 * Decompress [freq,val,freq,val,...] to expanded list.
 */
#include <iostream>
#include <vector>

std::vector<int> decompressRLElist(std::vector<int>& nums) {
    std::vector<int> out;
    for (size_t i = 0; i < nums.size(); i += 2) {
        int freq = nums[i], val = nums[i + 1];
        while (freq--) out.push_back(val);
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
    std::cout << "Problem: Decompress Run-Length Encoded List\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 4};
    auto r1 = decompressRLElist(a1);
    std::cout << "[1,2,3,4] -> ";
    print(r1);

    std::vector<int> a2 = {1, 1, 2, 3};
    auto r2 = decompressRLElist(a2);
    std::cout << "[1,1,2,3] -> ";
    print(r2);
}
