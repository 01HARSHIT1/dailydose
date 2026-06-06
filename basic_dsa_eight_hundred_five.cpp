/**
 * Basic DSA - Count Numbers with Non-Decreasing Digits (LeetCode 3519)
 * Digit DP on base-b representations with inclusion-exclusion over [l, r].
 */

#include <iostream>
#include <string>
#include <vector>

static constexpr int kMod = 1'000'000'007;

std::string decrementDecimalString(std::string value) {
    for (int index = static_cast<int>(value.size()) - 1; index >= 0; --index) {
        if (value[index] > '0') {
            --value[index];
            break;
        }
        value[index] = '9';
    }

    if (value.size() > 1 && value[0] == '0')
        return value.substr(1);

    return value;
}

std::vector<int> convertToBaseB(const std::string& decimalString, int base) {
    std::vector<int> digits;
    std::vector<int> currentValue(1, 0);

    for (const char character : decimalString) {
        const int digit = character - '0';

        int carry = 0;
        for (int index = 0; index < static_cast<int>(currentValue.size()); ++index) {
            const long long product =
                static_cast<long long>(currentValue[index]) * 10 + carry;
            currentValue[index] = static_cast<int>(product % base);
            carry = static_cast<int>(product / base);
        }

        while (carry > 0) {
            currentValue.push_back(carry % base);
            carry /= base;
        }

        carry = digit;
        for (int index = 0; index < static_cast<int>(currentValue.size()) && carry;
             ++index) {
            const int sum = currentValue[index] + carry;
            currentValue[index] = sum % base;
            carry = sum / base;
        }

        while (carry > 0) {
            currentValue.push_back(carry % base);
            carry /= base;
        }
    }

    for (int index = static_cast<int>(currentValue.size()) - 1; index >= 0; --index)
        digits.push_back(currentValue[index]);

    if (digits.empty())
        digits.push_back(0);

    return digits;
}

void padToSameLength(std::vector<int>& digits,
                       const std::vector<int>& targetLengthDigits) {
    digits.insert(digits.begin(), targetLengthDigits.size() - digits.size(), 0);
}

int countNonDecreasingUpTo(const std::vector<int>& digits, int base,
                           std::vector<std::vector<std::vector<int>>>& memo,
                           int position, int lastDigit, bool isTight) {
    if (position == static_cast<int>(digits.size()))
        return 1;

    if (memo[position][isTight ? 1 : 0][lastDigit] != -1)
        return memo[position][isTight ? 1 : 0][lastDigit];

    int result = 0;
    const int upperLimit = isTight ? digits[position] : base - 1;

    for (int digit = lastDigit; digit <= upperLimit; ++digit) {
        const bool nextTight = isTight && (digit == upperLimit);
        result = (result + countNonDecreasingUpTo(digits, base, memo, position + 1,
                                                  digit, nextTight)) %
                 kMod;
    }

    return memo[position][isTight ? 1 : 0][lastDigit] = result;
}

int countNonDecreasingUpToWithMemo(const std::vector<int>& digits, int base) {
    std::vector<std::vector<std::vector<int>>> memo(
        digits.size(), std::vector<std::vector<int>>(2, std::vector<int>(base, -1)));
    return countNonDecreasingUpTo(digits, base, memo, 0, 0, true);
}

int countNumbersWithNonDecreasingDigits(const std::string& left,
                                        const std::string& right, int base) {
    const std::vector<int> rightDigits = convertToBaseB(right, base);
    std::vector<int> leftMinusOneDigits = convertToBaseB(decrementDecimalString(left), base);

    padToSameLength(leftMinusOneDigits, rightDigits);

    const int rightCount = countNonDecreasingUpToWithMemo(rightDigits, base);
    const int leftCount = countNonDecreasingUpToWithMemo(leftMinusOneDigits, base);

    return (rightCount - leftCount + kMod) % kMod;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Numbers with Non-Decreasing Digits\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << countNumbersWithNonDecreasingDigits("23", "28", 8) << "\n";

    std::cout << "sample 2 -> "
              << countNumbersWithNonDecreasingDigits("2", "7", 2) << "\n";
}
