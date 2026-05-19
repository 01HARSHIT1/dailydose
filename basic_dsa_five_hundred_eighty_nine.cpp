/**
 * Basic DSA - Maximum Frequency Stack (LeetCode 895)
 * pop() removes the most recently pushed element among those with highest frequency. Stacks grouped by frequency count.
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

struct FreqStack {
    std::vector<int> st;
    std::unordered_map<int, int> freq;
    std::unordered_map<int, std::vector<int>> byFreq;
    int maxF = 0;

    void push(int val) {
        st.push_back(val);
        int f = ++freq[val];
        byFreq[f].push_back(val);
        maxF = std::max(maxF, f);
    }

    int pop() {
        int val = byFreq[maxF].back();
        byFreq[maxF].pop_back();
        if (byFreq[maxF].empty())
            --maxF;
        --freq[val];
        st.pop_back();
        return val;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Frequency Stack\n";
    std::cout << std::string(60, '=') << "\n";

    FreqStack fs;
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);
    std::cout << "pop -> " << fs.pop() << "\n";
    std::cout << "pop -> " << fs.pop() << "\n";
    std::cout << "pop -> " << fs.pop() << "\n";
}
