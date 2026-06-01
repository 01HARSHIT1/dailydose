/**
 * Basic DSA - Apply Substitutions (LeetCode 3481)
 * Recursively expand %key% placeholders using a replacement mapping.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string expandSubstitutions(const std::unordered_map<std::string, std::string>& mapping,
                                const std::string& text) {
    const std::size_t start = text.find('%');
    if (start == std::string::npos)
        return text;

    const std::size_t end = text.find('%', start + 1);
    if (end == std::string::npos)
        return text;

    const std::string key = text.substr(start + 1, end - start - 1);
    const auto iterator = mapping.find(key);
    const std::string replacement =
        iterator == mapping.end() ? "" : expandSubstitutions(mapping, iterator->second);

    return text.substr(0, start) + replacement +
           expandSubstitutions(mapping, text.substr(end + 1));
}

std::string applySubstitutions(const std::vector<std::vector<std::string>>& replacements,
                               const std::string& text) {
    std::unordered_map<std::string, std::string> mapping;
    for (const auto& entry : replacements)
        mapping[entry[0]] = entry[1];

    return expandSubstitutions(mapping, text);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Apply Substitutions\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << applySubstitutions({{"A", "bce"}, {"B", "ace"}, {"C", "abc%B%"}}, "%A%_%B%_%C%")
              << "\n";

    std::cout << "sample 2 -> " << applySubstitutions({{"A", "cat"}}, "The %A% ran fast") << "\n";
}
