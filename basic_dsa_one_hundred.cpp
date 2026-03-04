/**
 * Basic DSA - Sign of the Product of an Array (LeetCode 1822)
 * Return 1, -1, or 0 based on product sign (without computing product).
 */
#include <iostream>
#include <vector>

int arraySign(std::vector<int>& nums) {
    int neg = 0;
    for (int x : nums) {
        if (x == 0) return 0;
        if (x < 0) neg++;
    }
    return neg % 2 == 0 ? 1 : -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sign of the Product of an Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {-1, -2, -3, -4, 3, 2, 1};
    std::cout << "[-1,-2,-3,-4,3,2,1] -> " << arraySign(a1) << "\n";

    std::vector<int> a2 = {1, 5, 0, 2, -3};
    std::cout << "[1,5,0,2,-3] -> " << arraySign(a2) << "\n";

    std::vector<int> a3 = {-1, 1, -1, 1, -1};
    std::cout << "[-1,1,-1,1,-1] -> " << arraySign(a3) << "\n";
}
