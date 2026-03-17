/**
 * Basic DSA - Lemonade Change (LeetCode 860)
 * Return true if can give change for all $5 lemonades.
 */
#include <iostream>
#include <vector>

bool lemonadeChange(std::vector<int>& bills) {
    int fives = 0, tens = 0;
    for (int b : bills) {
        if (b == 5) fives++;
        else if (b == 10) {
            if (fives == 0) return false;
            fives--; tens++;
        } else {
            if (tens > 0 && fives > 0) { tens--; fives--; }
            else if (fives >= 3) fives -= 3;
            else return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Lemonade Change\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {5, 5, 5, 10, 20};
    std::cout << "[5,5,5,10,20] -> " << (lemonadeChange(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {5, 5, 10, 10, 20};
    std::cout << "[5,5,10,10,20] -> " << (lemonadeChange(v2) ? "true" : "false") << "\n";
}
