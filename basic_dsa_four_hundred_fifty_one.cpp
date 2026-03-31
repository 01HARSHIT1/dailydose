/**
 * Basic DSA - Maximum Number of Balls in a Box (LeetCode 1742)
 * For each n in [lowLimit, highLimit], a ball goes in the box labeled sum of digits of n.
 */
#include <algorithm>
#include <iostream>

int countBalls(int lowLimit, int highLimit) {
    int cnt[46] = {};
    for (int n = lowLimit; n <= highLimit; ++n) {
        int s = 0, x = n;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        ++cnt[s];
    }
    return *std::max_element(cnt, cnt + 46);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Number of Balls in a Box\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "low=1, high=10 -> " << countBalls(1, 10) << "\n";
    std::cout << "low=5, high=15 -> " << countBalls(5, 15) << "\n";
    std::cout << "low=19, high=28 -> " << countBalls(19, 28) << "\n";
}
