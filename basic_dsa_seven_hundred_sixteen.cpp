/**
 * Basic DSA - Assign Elements to Groups with Constraints (LeetCode 3447)
 * Sieve multiples: smallest element index j where groups[i] % elements[j] == 0.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> assignElements(const std::vector<int>& groups,
                                const std::vector<int>& elements) {
    int mx = *std::max_element(groups.begin(), groups.end());
    std::vector<int> lookup(mx + 1, -1);

    for (int j = 0; j < static_cast<int>(elements.size()); ++j) {
        int x = elements[j];
        if (x > mx || lookup[x] != -1)
            continue;
        for (int y = x; y <= mx; y += x) {
            if (lookup[y] == -1)
                lookup[y] = j;
        }
    }

    std::vector<int> assigned;
    assigned.reserve(groups.size());
    for (int g : groups)
        assigned.push_back(lookup[g]);
    return assigned;
}

void printAssigned(const std::vector<int>& assigned) {
    std::cout << "[";
    for (size_t i = 0; i < assigned.size(); ++i) {
        if (i)
            std::cout << ",";
        std::cout << assigned[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Assign Elements to Groups with Constraints\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printAssigned(assignElements({8, 4, 3, 2, 4}, {4, 2}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printAssigned(assignElements({2, 3, 5, 7}, {5, 3, 3}));
    std::cout << "\n";
}
