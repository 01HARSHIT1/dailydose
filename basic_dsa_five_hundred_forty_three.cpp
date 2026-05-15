/**
 * Basic DSA - Sum of Subarray Minimums (LeetCode 907)
 * Each arr[m] contributes arr[m] * (m - prevLess) * (nextLess - m) subarrays where it is minimum. Monotone stack + sentinel index n.
 */
#include <iostream>
#include <stack>
#include <vector>

int sumSubarrayMins(const std::vector<int>& arr) {
    const int MOD = 1000000007;
    std::stack<int> st;
    long long res = 0;
    int n = static_cast<int>(arr.size());
    for (int i = 0; i <= n; ++i) {
        while (!st.empty() &&
               (i == n || arr[static_cast<size_t>(st.top())] > arr[static_cast<size_t>(i)])) {
            int m = st.top();
            st.pop();
            int l = st.empty() ? -1 : st.top();
            res = (res + (long long)arr[static_cast<size_t>(m)] * (m - l) * (i - m)) % MOD;
        }
        st.push(i);
    }
    return static_cast<int>(res);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of Subarray Minimums\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[3,1,2,4]        -> " << sumSubarrayMins({3, 1, 2, 4}) << "\n";
    std::cout << "[1]              -> " << sumSubarrayMins({1}) << "\n";
}
