/**
 * Basic DSA - Task Scheduler (LeetCode 621)
 * Min intervals to complete tasks with cooldown n between same task.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int leastInterval(std::vector<char>& tasks, int n) {
    int count[26] = {};
    for (char c : tasks) count[c - 'A']++;
    int maxFreq = *std::max_element(count, count + 26);
    int maxCount = 0;
    for (int c : count) if (c == maxFreq) maxCount++;
    int slots = (maxFreq - 1) * (n + 1) + maxCount;
    return std::max(slots, (int)tasks.size());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Task Scheduler\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<char> a1 = {'A','A','A','B','B','B'};
    std::cout << "[A,A,A,B,B,B], n=2 -> " << leastInterval(a1, 2) << "\n";

    std::vector<char> a2 = {'A','A','A','B','B','B'};
    std::cout << "[A,A,A,B,B,B], n=0 -> " << leastInterval(a2, 0) << "\n";

    std::vector<char> a3 = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    std::cout << "[A,A,A,A,A,A,B,C,D,E,F,G], n=2 -> " << leastInterval(a3, 2) << "\n";
}
