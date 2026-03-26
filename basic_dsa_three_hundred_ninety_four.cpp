/**
 * Basic DSA - Walking Robot Simulation (LeetCode 874)
 * Commands: k>0 move k steps, -1 turn right, -2 turn left. Obstacles block movement.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
    std::unordered_set<std::string> obs;
    for (const auto& o : obstacles)
        obs.insert(std::to_string(o[0]) + "," + std::to_string(o[1]));
    int x = 0;
    int y = 0;
    int dir = 0;
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    int best = 0;
    for (int c : commands) {
        if (c == -1) {
            dir = (dir + 1) % 4;
        } else if (c == -2) {
            dir = (dir + 3) % 4;
        } else {
            for (int k = 0; k < c; ++k) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                std::string key = std::to_string(nx) + "," + std::to_string(ny);
                if (obs.count(key))
                    break;
                x = nx;
                y = ny;
                best = std::max(best, x * x + y * y);
            }
        }
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Walking Robot Simulation\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> cmd1 = {4, -1, 3};
    std::vector<std::vector<int>> ob1;
    std::cout << "[4,-1,3], no obstacles -> " << robotSim(cmd1, ob1) << "\n";

    std::vector<int> cmd2 = {4, -1, 4, -2, 4};
    std::vector<std::vector<int>> ob2 = {{2, 4}};
    std::cout << "[4,-1,4,-2,4], obstacle [2,4] -> " << robotSim(cmd2, ob2) << "\n";
}
