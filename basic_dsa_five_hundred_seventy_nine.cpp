/**
 * Basic DSA - Implement Rand10() Using Rand7() (LeetCode 470)
 * Two calls build a uniform 0..48; reject x>=40; otherwise x%10+1 is uniform 1..10 (each accepted x maps 4 times).
 */
#include <iostream>
#include <random>

int mockRand7(std::mt19937& gen) {
    std::uniform_int_distribution<int> dist(1, 7);
    return dist(gen);
}

int rand10FromRand7(std::mt19937& gen) {
    while (true) {
        int x = (mockRand7(gen) - 1) * 7 + (mockRand7(gen) - 1);
        if (x < 40)
            return x % 10 + 1;
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Rand10 from Rand7 (rejection sampling demo)\n";
    std::cout << std::string(60, '=') << "\n";

    std::mt19937 gen(12345);
    std::cout << "10 draws: ";
    for (int i = 0; i < 10; ++i)
        std::cout << rand10FromRand7(gen) << (i < 9 ? " " : "");
    std::cout << "\n";
}
