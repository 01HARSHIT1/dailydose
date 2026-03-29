/**
 * Basic DSA - Slowest Key (LeetCode 1629)
 * releaseTimes[i] is when keysPressed[i] is released; first key duration is releaseTimes[0].
 */
#include <iostream>
#include <string>
#include <vector>

char slowestKey(const std::vector<int>& releaseTimes, const std::string& keysPressed) {
    char ans = keysPressed[0];
    int best = releaseTimes[0];
    for (size_t i = 1; i < keysPressed.size(); ++i) {
        int d = releaseTimes[i] - releaseTimes[i - 1];
        if (d > best || (d == best && keysPressed[i] > ans)) {
            best = d;
            ans = keysPressed[i];
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Slowest Key\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> t1 = {9, 29, 49, 50};
    std::cout << "\"cbcd\" -> " << slowestKey(t1, "cbcd") << "\n";

    std::vector<int> t2 = {12, 23, 36, 46, 62};
    std::cout << "\"spuda\" -> " << slowestKey(t2, "spuda") << "\n";
}
