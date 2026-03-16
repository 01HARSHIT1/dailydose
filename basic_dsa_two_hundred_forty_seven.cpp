/**
 * Basic DSA - Check If N and Its Double Exist (LeetCode 1346)
 * Return true if exists i,j with arr[i] == 2 * arr[j].
 */
#include <iostream>
#include <vector>
#include <unordered_set>

bool checkIfExist(std::vector<int>& arr) {
    std::unordered_set<int> seen;
    for (int x : arr) {
        if (seen.count(x * 2) || (x % 2 == 0 && seen.count(x / 2)))
            return true;
        seen.insert(x);
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check If N and Its Double Exist\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {10, 2, 5, 3};
    std::cout << "[10,2,5,3] -> " << (checkIfExist(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {3, 1, 7, 11};
    std::cout << "[3,1,7,11] -> " << (checkIfExist(v2) ? "true" : "false") << "\n";

    std::vector<int> v3 = {-2, 0, 10, -19, 4, 6, -8};
    std::cout << "[-2,0,10,-19,4,6,-8] -> " << (checkIfExist(v3) ? "true" : "false") << "\n";
}
