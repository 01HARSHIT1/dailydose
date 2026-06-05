/**
 * Basic DSA - Multiply Two Polynomials (LeetCode 3549)
 * Convolve coefficient arrays to produce product polynomial coefficients.
 */

#include <iostream>
#include <vector>

std::vector<int> multiplyPolynomials(const std::vector<int>& firstPoly,
                                     const std::vector<int>& secondPoly) {
    const int resultSize =
        static_cast<int>(firstPoly.size() + secondPoly.size() - 1);
    std::vector<int> result(resultSize, 0);

    for (int firstIndex = 0; firstIndex < static_cast<int>(firstPoly.size());
         ++firstIndex) {
        for (int secondIndex = 0;
             secondIndex < static_cast<int>(secondPoly.size()); ++secondIndex) {
            result[firstIndex + secondIndex] +=
                firstPoly[firstIndex] * secondPoly[secondIndex];
        }
    }

    return result;
}

void printCoefficients(const std::vector<int>& coefficients) {
    std::cout << "[";
    for (int index = 0; index < static_cast<int>(coefficients.size()); ++index) {
        if (index > 0)
            std::cout << ",";
        std::cout << coefficients[index];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Multiply Two Polynomials\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printCoefficients(multiplyPolynomials({3, 2, 5}, {1, 4}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printCoefficients(multiplyPolynomials({1, 0, -2}, {-1}));
    std::cout << "\n";
}
