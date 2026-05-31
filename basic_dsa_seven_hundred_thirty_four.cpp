/**
 * Basic DSA - Check If Digits Are Equal in String After Operations II (LeetCode 3463)
 * O(n) check using binomial coefficients mod 10 (Lucas theorem).
 */

#include <iostream>
#include <string>

int binomial(int n, int k) {
    int result = 1;
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int lucasMod(int n, int k, int prime) {
    int result = 1;
    while (n > 0 || k > 0) {
        result *= binomial(n % prime, k % prime);
        result %= prime;
        n /= prime;
        k /= prime;
    }
    return result;
}

int binomialMod10(int n, int k) {
    static constexpr int lookup[2][5] = {
        {0, 6, 2, 8, 4},
        {5, 1, 7, 3, 9},
    };
    return lookup[lucasMod(n, k, 2)][lucasMod(n, k, 5)];
}

bool hasSameDigits(const std::string& s) {
    const int n = static_cast<int>(s.size());
    int left = 0;
    int right = 0;

    for (int i = 0; i + 1 < n; ++i) {
        const int coeff = binomialMod10(n - 2, i);
        left = (left + coeff * (s[i] - '0')) % 10;
        right = (right + coeff * (s[i + 1] - '0')) % 10;
    }
    return left == right;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check If Digits Are Equal in String After Operations II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << hasSameDigits("3902") << "\n";
    std::cout << "sample 2 -> " << hasSameDigits("34789") << "\n";
}
