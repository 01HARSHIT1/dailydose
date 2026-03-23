/**
 * Basic DSA - Baseball Game (LeetCode 682)
 * Compute score from ops: int, +, D, C.
 */
#include <iostream>
#include <vector>
#include <string>

int calPoints(std::vector<std::string>& operations) {
    std::vector<int> st;
    for (const std::string& op : operations) {
        if (op == "+") {
            int n = st.size();
            st.push_back(st[n - 1] + st[n - 2]);
        } else if (op == "D") st.push_back(2 * st.back());
        else if (op == "C") st.pop_back();
        else st.push_back(std::stoi(op));
    }
    int sum = 0;
    for (int x : st) sum += x;
    return sum;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Baseball Game\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::string> o1 = {"5", "2", "C", "D", "+"};
    std::cout << "example 1 -> " << calPoints(o1) << "\n";

    std::vector<std::string> o2 = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    std::cout << "example 2 -> " << calPoints(o2) << "\n";
}
