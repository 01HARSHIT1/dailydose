/**
 * Basic DSA - Find the Peaks (LeetCode 2951)
 * Index i is a peak if mountain[i] > mountain[i-1] and mountain[i] > mountain[i+1].
 */
#include <iostream>
#include <vector>

std::vector<int> findPeaks(const std::vector<int>& mountain) {
    std::vector<int> ans;
    for (int i = 1; i + 1 < static_cast<int>(mountain.size()); ++i) {
        if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
            ans.push_back(i);
    }
    return ans;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Peaks\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> m1 = {1, 4, 3, 8, 5};
    printVec(m1);
    std::cout << " -> ";
    printVec(findPeaks(m1));
    std::cout << "\n";

    std::vector<int> m2 = {1, 2, 3};
    printVec(m2);
    std::cout << " -> ";
    printVec(findPeaks(m2));
    std::cout << "\n";
}
