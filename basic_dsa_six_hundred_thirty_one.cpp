/**
 * Basic DSA - Distribute Money to Maximum Children (LeetCode 2591)
 * Everyone gets >=1; maximize children with exactly 8, while avoiding the forbidden 4 (rule: no one gets exactly 4).
 */
#include <algorithm>
#include <iostream>

int distMoney(int money, int children) {
    if (money < children)
        return -1;

    money -= children; // give everyone the mandatory 1 dollar
    int eights = std::min(money / 7, children);
    money -= eights * 7;
    int remainingChildren = children - eights;

    if (remainingChildren == 0 && money > 0)
        --eights; // extra money must go somewhere; one child exceeds 8
    else if (remainingChildren == 1 && money == 3)
        --eights; // the last child would end up with exactly 4 dollars

    return eights;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Distribute Money to Maximum Children\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << distMoney(20, 3) << "\n";
    std::cout << "sample 2 -> " << distMoney(16, 2) << "\n";
}
