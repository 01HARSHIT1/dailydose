/**
 * Basic DSA - Average Salary Excluding the Minimum and Maximum Salary (LeetCode 1491)
 * At least three distinct salaries; drop one min and one max, average the rest.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

double average(const std::vector<int>& salary) {
    int mn = salary[0];
    int mx = salary[0];
    long long sum = 0;
    for (int x : salary) {
        mn = std::min(mn, x);
        mx = std::max(mx, x);
        sum += x;
    }
    return static_cast<double>(sum - mn - mx) / static_cast<double>(salary.size() - 2);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Average Salary Excluding the Minimum and Maximum Salary\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {4000, 3000, 1000, 2000};
    std::cout << "[4000,3000,1000,2000] -> " << average(v1) << "\n";

    std::vector<int> v2 = {1000, 2000, 3000};
    std::cout << "[1000,2000,3000] -> " << average(v2) << "\n";
}
