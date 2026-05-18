/**
 * Basic DSA - Logger Rate Limiter (LeetCode 359)
 * Each unique message prints at most once every 10 seconds. Hash map stores earliest time the message may print again.
 */
#include <iostream>
#include <string>
#include <unordered_map>

struct Logger {
    std::unordered_map<std::string, int> nextAllowed;

    bool shouldPrintMessage(int timestamp, const std::string& message) {
        auto it = nextAllowed.find(message);
        if (it != nextAllowed.end() && it->second > timestamp)
            return false;
        nextAllowed[message] = timestamp + 10;
        return true;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Logger Rate Limiter\n";
    std::cout << std::string(60, '=') << "\n";

    Logger log;
    std::cout << "1 foo  -> " << (log.shouldPrintMessage(1, "foo") ? "true" : "false") << "\n";
    std::cout << "2 bar  -> " << (log.shouldPrintMessage(2, "bar") ? "true" : "false") << "\n";
    std::cout << "3 foo  -> " << (log.shouldPrintMessage(3, "foo") ? "true" : "false") << "\n";
    std::cout << "8 bar  -> " << (log.shouldPrintMessage(8, "bar") ? "true" : "false") << "\n";
    std::cout << "10 foo -> " << (log.shouldPrintMessage(10, "foo") ? "true" : "false") << "\n";
    std::cout << "11 foo -> " << (log.shouldPrintMessage(11, "foo") ? "true" : "false") << "\n";
}
