/**
 * Basic DSA - Lexicographically Smallest String After Adjacent Removals
 * (LeetCode 3563)
 * Interval DP: keep s[i] or remove s[i] with a consecutive s[k] when middle clears.
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

bool areAlphabetNeighbors(char first, char second) {
    const int difference = std::abs(first - second);
    return difference == 1 || difference == 25;
}

std::string lexicographicallySmallestAfterRemovals(const std::string& input) {
    const int length = static_cast<int>(input.size());
    std::vector<std::vector<std::string>> smallestResult(
        length + 1, std::vector<std::string>(length + 1));

    for (int intervalLength = 1; intervalLength <= length; ++intervalLength) {
        for (int start = 0; start + intervalLength <= length; ++start) {
            const int end = start + intervalLength;
            std::string bestString = input[start] + smallestResult[start + 1][end];

            for (int partner = start + 1; partner < end; ++partner) {
                if (areAlphabetNeighbors(input[start], input[partner]) &&
                    smallestResult[start + 1][partner].empty()) {
                    bestString =
                        std::min(bestString, smallestResult[partner + 1][end]);
                }
            }

            smallestResult[start][end] = bestString;
        }
    }

    return smallestResult[0][length];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Lexicographically Smallest String After Adjacent Removals\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> \"" << lexicographicallySmallestAfterRemovals("abc")
              << "\"\n";
    std::cout << "sample 2 -> \"" << lexicographicallySmallestAfterRemovals("bcda")
              << "\"\n";
    std::cout << "sample 3 -> \"" << lexicographicallySmallestAfterRemovals("zdce")
              << "\"\n";
}
