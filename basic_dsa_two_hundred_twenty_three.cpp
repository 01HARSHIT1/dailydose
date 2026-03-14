/**
 * Basic DSA - Guess Number Higher or Lower (LeetCode 374)
 * Guess a number 1 to n using binary search API.
 */
#include <iostream>

int pick = 6;  // simulate: answer is 6

int guess(int num) {
    if (num == pick) return 0;
    return num < pick ? 1 : -1;
}

int guessNumber(int n) {
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int g = guess(mid);
        if (g == 0) return mid;
        if (g == 1) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Guess Number Higher or Lower\n";
    std::cout << std::string(60, '=') << "\n";

    pick = 6;
    std::cout << "n=10, pick=6 -> " << guessNumber(10) << "\n";

    pick = 1;
    std::cout << "n=1, pick=1 -> " << guessNumber(1) << "\n";

    pick = 2;
    std::cout << "n=2, pick=2 -> " << guessNumber(2) << "\n";
}
