/**
 * Basic DSA - Encode and Decode TinyURL (LeetCode 535)
 * Encode URL to short form and decode back (simple counter-based).
 */
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
    std::unordered_map<std::string, std::string> db;
    int id = 0;
public:
    std::string encode(std::string longUrl) {
        std::string shortUrl = "https://tiny.com/" + std::to_string(id++);
        db[shortUrl] = longUrl;
        return shortUrl;
    }
    std::string decode(std::string shortUrl) {
        return db[shortUrl];
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Encode and Decode TinyURL\n";
    std::cout << std::string(60, '=') << "\n";

    Solution sol;
    std::string url = "https://leetcode.com/problems/design-tinyurl";
    std::string encoded = sol.encode(url);
    std::string decoded = sol.decode(encoded);
    std::cout << "Encode: " << url << " -> " << encoded << "\n";
    std::cout << "Decode: " << encoded << " -> " << decoded << "\n";
    std::cout << "Match: " << (url == decoded ? "true" : "false") << "\n";
}
