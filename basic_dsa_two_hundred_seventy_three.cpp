/**
 * Basic DSA - Guess Number Higher or Lower (LeetCode 374)
 * Guess the number using API guess(n) -> -1,0,1.
 */
#include <iostream>

int pick = 6;  // mock target
int guess(int n) {
    if (n < pick) return 1;
    if (n > pick) return -1;
    return 0;
}

int guessNumber(int n) {
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int g = guess(mid);
        if (g == 0) return mid;
        if (g == 1) lo = mid + 1;
        else hi = mid - 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Guess Number Higher or Lower\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=10, pick=6 -> " << guessNumber(10) << "\n";
    pick = 1;
    std::cout << "n=1, pick=1 -> " << guessNumber(1) << "\n";
}
