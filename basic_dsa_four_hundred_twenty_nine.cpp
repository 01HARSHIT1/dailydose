/**
 * Basic DSA - Destination City (LeetCode 1436)
 * paths[i] = [from, to] forms a line without loops; return the city with no outgoing path.
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

std::string destCity(const std::vector<std::vector<std::string>>& paths) {
    std::unordered_set<std::string> from;
    from.reserve(paths.size() * 2);
    for (const auto& leg : paths)
        from.insert(leg[0]);
    for (const auto& leg : paths) {
        if (!from.count(leg[1]))
            return leg[1];
    }
    return "";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Destination City\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<std::string>> p1 = {
        {"London", "New York"},
        {"New York", "Lima"},
        {"Lima", "Sao Paulo"}};
    std::cout << "three legs -> " << destCity(p1) << "\n";

    std::vector<std::vector<std::string>> p2 = {{"B", "C"}, {"D", "B"}, {"C", "A"}};
    std::cout << "second example -> " << destCity(p2) << "\n";
}
