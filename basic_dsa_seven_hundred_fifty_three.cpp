/**
 * Basic DSA - Design Spreadsheet (LeetCode 3484)
 * Store cell values in a hash map and evaluate simple addition formulas.
 */

#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

class Spreadsheet {
    std::unordered_map<std::string, int> cells;

    int readToken(const std::string& token) const {
        if (!token.empty() && std::isdigit(static_cast<unsigned char>(token[0])))
            return std::stoi(token);

        const auto iterator = cells.find(token);
        return iterator == cells.end() ? 0 : iterator->second;
    }

public:
    explicit Spreadsheet(int /*rows*/) {}

    void setCell(const std::string& cell, int value) { cells[cell] = value; }

    void resetCell(const std::string& cell) { cells.erase(cell); }

    int getValue(const std::string& formula) const {
        const std::size_t plusIndex = formula.find('+');
        return readToken(formula.substr(1, plusIndex - 1)) +
               readToken(formula.substr(plusIndex + 1));
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Design Spreadsheet\n";
    std::cout << std::string(60, '=') << "\n";

    Spreadsheet spreadsheet(3);

    std::cout << "sample 1 -> " << spreadsheet.getValue("=5+7") << "\n";

    spreadsheet.setCell("A1", 10);
    std::cout << "sample 2 -> " << spreadsheet.getValue("=A1+6") << "\n";

    spreadsheet.setCell("B2", 15);
    std::cout << "sample 3 -> " << spreadsheet.getValue("=A1+B2") << "\n";

    spreadsheet.resetCell("A1");
    std::cout << "sample 4 -> " << spreadsheet.getValue("=A1+B2") << "\n";
}
