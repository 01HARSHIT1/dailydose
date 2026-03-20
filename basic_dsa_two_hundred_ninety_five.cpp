/**
 * Basic DSA - Multiply Strings (LeetCode 43)
 * Return product of two non-negative integer strings.
 */
#include <iostream>
#include <string>
#include <vector>

std::string multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int n = num1.size(), m = num2.size();
    std::vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int p = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1];
            res[i + j + 1] = p % 10;
            res[i + j] += p / 10;
        }
    }
    std::string ans;
    int k = 0;
    while (k < (int)res.size() && res[k] == 0) k++;
    for (; k < (int)res.size(); k++) ans.push_back('0' + res[k]);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Multiply Strings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "2 * 3 -> " << multiply("2", "3") << "\n";
    std::cout << "123 * 456 -> " << multiply("123", "456") << "\n";
    std::cout << "0 * 9999 -> " << multiply("0", "9999") << "\n";
}
