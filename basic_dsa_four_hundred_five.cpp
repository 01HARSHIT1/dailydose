/**
 * Basic DSA - Find the Town Judge (LeetCode 997)
 * In a town of n people labeled 1..n, trust[i] = [a,b] means a trusts b.
 * The judge trusts nobody and is trusted by everyone else (n-1 people).
 */
#include <iostream>
#include <string>
#include <vector>

int findJudge(int n, std::vector<std::vector<int>>& trust) {
    std::vector<int> score(n + 1);
    for (const auto& t : trust) {
        score[t[0]]--;
        score[t[1]]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (score[i] == n - 1)
            return i;
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Town Judge\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> t1 = {{1, 2}};
    std::cout << "n=2, [[1,2]] -> " << findJudge(2, t1) << "\n";

    std::vector<std::vector<int>> t2 = {{1, 3}, {2, 3}};
    std::cout << "n=3, [[1,3],[2,3]] -> " << findJudge(3, t2) << "\n";

    std::vector<std::vector<int>> t3 = {{1, 3}, {2, 3}, {3, 1}};
    std::cout << "n=3, [[1,3],[2,3],[3,1]] -> " << findJudge(3, t3) << "\n";
}
