/**
 * Basic DSA - Fizz Buzz (LeetCode 412)
 * Replace multiples of 3 with Fizz, 5 with Buzz, both with FizzBuzz.
 */
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> out;
    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) out.push_back("FizzBuzz");
        else if (i % 3 == 0) out.push_back("Fizz");
        else if (i % 5 == 0) out.push_back("Buzz");
        else out.push_back(std::to_string(i));
    }
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Fizz Buzz\n";
    std::cout << std::string(60, '=') << "\n";

    auto r = fizzBuzz(15);
    std::cout << "n=15 -> ";
    for (size_t i = 0; i < r.size(); i++) {
        std::cout << r[i];
        if (i + 1 < r.size()) std::cout << ", ";
    }
    std::cout << "\n";
}
