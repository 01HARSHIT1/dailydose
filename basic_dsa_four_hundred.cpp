/**
 * Basic DSA - Long Pressed Name (LeetCode 925)
 * typed may repeat characters; determine if it could still type name in order.
 */
#include <iostream>
#include <string>

bool isLongPressedName(const std::string& name, const std::string& typed) {
    int i = 0;
    int j = 0;
    int n = static_cast<int>(name.size());
    int m = static_cast<int>(typed.size());
    while (j < m) {
        if (i < n && name[i] == typed[j]) {
            ++i;
            ++j;
        } else if (j > 0 && typed[j] == typed[j - 1]) {
            ++j;
        } else {
            return false;
        }
    }
    return i == n;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Long Pressed Name\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "alex / aaleex -> " << (isLongPressedName("alex", "aaleex") ? "true" : "false") << "\n";
    std::cout << "saeed / ssaaedd -> " << (isLongPressedName("saeed", "ssaaedd") ? "true" : "false") << "\n";
    std::cout << "leelee / lleeelee -> " << (isLongPressedName("leelee", "lleeelee") ? "true" : "false") << "\n";
}
