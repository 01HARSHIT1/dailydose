/**
 * Basic DSA - Daily Temperatures (LeetCode 739)
 * For each day, days until a warmer temperature (0 if none).
 */
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    int n = temperatures.size();
    std::vector<int> ans(n);
    std::stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
            int j = st.top(); st.pop();
            ans[j] = i - j;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Daily Temperatures\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    auto r1 = dailyTemperatures(t1);
    std::cout << "[73,74,...] -> [";
    for (int i = 0; i < (int)r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<int> t2 = {30, 40, 50, 60};
    auto r2 = dailyTemperatures(t2);
    std::cout << "[30,40,50,60] -> [";
    for (int i = 0; i < (int)r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
