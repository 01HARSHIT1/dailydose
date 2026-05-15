/**
 * Basic DSA - Asteroid Collision (LeetCode 735)
 * Stack keeps surviving asteroids: positives move right; negatives collide with stack tops.
 */
#include <iostream>
#include <vector>

std::vector<int> asteroidCollision(const std::vector<int>& asteroids) {
    std::vector<int> st;
    st.reserve(asteroids.size());
    for (int a : asteroids) {
        bool alive = true;
        while (alive && a < 0 && !st.empty() && st.back() > 0) {
            if (st.back() < -a)
                st.pop_back();
            else if (st.back() == -a) {
                st.pop_back();
                alive = false;
            } else
                alive = false;
        }
        if (alive)
            st.push_back(a);
    }
    return st;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Asteroid Collision\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(asteroidCollision({5, 10, -5}));
    printVec(asteroidCollision({8, -8}));
    printVec(asteroidCollision({10, 2, -5}));
}
