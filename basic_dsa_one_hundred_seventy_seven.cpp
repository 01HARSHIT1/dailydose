/**
 * Basic DSA - Fizz Buzz (LeetCode 412)
 * Return string array: "FizzBuzz" if divisible by 3 and 5, "Fizz" by 3, "Buzz" by 5, else number.
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

    auto r1 = fizzBuzz(15);
    std::cout << "n=15 -> [";
    for (size_t i = 0; i < r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    auto r2 = fizzBuzz(5);
    std::cout << "n=5 -> [";
    for (size_t i = 0; i < r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
