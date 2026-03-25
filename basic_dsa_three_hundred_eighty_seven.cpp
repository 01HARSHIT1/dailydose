/**
 * Basic DSA - Unique Morse Code Words (LeetCode 804)
 * How many different Morse encodings appear among the words (lowercase a-z)?
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int uniqueMorseRepresentations(std::vector<std::string>& words) {
    static const std::vector<std::string> morse = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
        "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    std::unordered_set<std::string> seen;
    for (const std::string& w : words) {
        std::string code;
        for (char c : w)
            code += morse[static_cast<unsigned char>(c - 'a')];
        seen.insert(std::move(code));
    }
    return static_cast<int>(seen.size());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Unique Morse Code Words\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::string> w1 = {"gin", "zen", "gig", "msg"};
    std::cout << "[gin,zen,gig,msg] -> " << uniqueMorseRepresentations(w1) << "\n";

    std::vector<std::string> w2 = {"a"};
    std::cout << "[a] -> " << uniqueMorseRepresentations(w2) << "\n";
}
