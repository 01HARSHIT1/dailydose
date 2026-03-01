/**
 * Basic DSA - Lemonade Change (LeetCode 860)
 * Can provide change for $5 bills when customers pay $5, $10, or $20?
 */
#include <iostream>
#include <vector>

bool lemonadeChange(std::vector<int>& bills) {
    int five = 0, ten = 0;
    for (int b : bills) {
        if (b == 5) five++;
        else if (b == 10) {
            if (five == 0) return false;
            five--;
            ten++;
        } else {
            if (ten > 0 && five > 0) { ten--; five--; }
            else if (five >= 3) five -= 3;
            else return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Lemonade Change\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {5, 5, 5, 10, 20};
    std::cout << "[5,5,5,10,20] -> " << (lemonadeChange(a1) ? "true" : "false") << "\n";

    std::vector<int> a2 = {5, 5, 10, 10, 20};
    std::cout << "[5,5,10,10,20] -> " << (lemonadeChange(a2) ? "true" : "false") << "\n";

    std::vector<int> a3 = {5, 5, 10};
    std::cout << "[5,5,10] -> " << (lemonadeChange(a3) ? "true" : "false") << "\n";
}
