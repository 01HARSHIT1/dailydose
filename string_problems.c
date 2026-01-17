#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

/**
 * String DSA Interview Problems
 * Collection of common string problems with solutions
 */

// Problem 1: Reverse String
// Reverse a string in-place
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

// Problem 2: Valid Anagram
// Check if two strings are anagrams
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1) - limited to 26 characters
 */
bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }
    
    int count[26] = {0};
    
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}

// Problem 3: First Unique Character
// Find the first non-repeating character in a string
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1) - limited to 26 characters
 */
int firstUniqChar(char* s) {
    int count[26] = {0};
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }
    
    for (int i = 0; i < len; i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }
    
    return -1;
}

// Problem 4: Valid Palindrome
// Check if a string is a palindrome (considering alphanumeric only)
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

// Problem 5: Longest Common Prefix
// Find the longest common prefix string among an array of strings
/**
 * Time Complexity: O(S) where S is sum of all characters
 * Space Complexity: O(1)
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    
    int prefixLen = strlen(strs[0]);
    
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (j < prefixLen && strs[0][j] == strs[i][j]) {
            j++;
        }
        prefixLen = j;
        if (prefixLen == 0) {
            return "";
        }
    }
    
    char* result = (char*)malloc((prefixLen + 1) * sizeof(char));
    strncpy(result, strs[0], prefixLen);
    result[prefixLen] = '\0';
    return result;
}

// Problem 6: String to Integer (atoi)
// Convert string to integer
/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int myAtoi(char* s) {
    // Skip whitespace
    while (*s == ' ') {
        s++;
    }
    
    if (*s == '\0') {
        return 0;
    }
    
    int sign = 1;
    if (*s == '-') {
        sign = -1;
        s++;
    } else if (*s == '+') {
        s++;
    }
    
    long result = 0;
    while (isdigit(*s)) {
        result = result * 10 + (*s - '0');
        if (result * sign > INT_MAX) {
            return INT_MAX;
        }
        if (result * sign < INT_MIN) {
            return INT_MIN;
        }
        s++;
    }
    
    return (int)(result * sign);
}

// Problem 7: Implement strStr() (Find Needle in Haystack)
// Find the first occurrence of needle in haystack
/**
 * Time Complexity: O(n * m)
 * Space Complexity: O(1)
 */
int strStr(char* haystack, char* needle) {
    if (*needle == '\0') {
        return 0;
    }
    
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);
    
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        int j = 0;
        while (j < needleLen && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == needleLen) {
            return i;
        }
    }
    
    return -1;
}

// Problem 8: Reverse Words in a String
// Reverse the order of words in a string
/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void reverseWords(char* s) {
    int len = strlen(s);
    if (len == 0) {
        return;
    }
    
    // Reverse entire string
    reverseString(s, len);
    
    // Reverse each word
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverseString(s + start, i - start);
            start = i + 1;
        }
    }
}

// Problem 9: Longest Substring Without Repeating Characters
// Find length of longest substring without repeating characters
/**
 * Time Complexity: O(n)
 * Space Complexity: O(min(n, m)) where m is charset size
 */
int lengthOfLongestSubstring(char* s) {
    int charIndex[128];  // ASCII characters
    memset(charIndex, -1, sizeof(charIndex));
    
    int maxLength = 0;
    int start = 0;
    int len = strlen(s);
    
    for (int end = 0; end < len; end++) {
        if (charIndex[s[end]] >= start) {
            start = charIndex[s[end]] + 1;
        }
        
        charIndex[s[end]] = end;
        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}

// Problem 10: Valid Parentheses
// Check if string contains valid parentheses
/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
bool isValidParentheses(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1) {
                free(stack);
                return false;
            }
            
            char topChar = stack[top--];
            if ((s[i] == ')' && topChar != '(') ||
                (s[i] == '}' && topChar != '{') ||
                (s[i] == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }
    
    bool result = (top == -1);
    free(stack);
    return result;
}

// Problem 11: Longest Palindromic Substring
// Find the longest palindromic substring
/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
int expandAroundCenter(char* s, int left, int right) {
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) {
        return "";
    }
    
    int start = 0;
    int maxLength = 1;
    
    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int currentLength = (len1 > len2) ? len1 : len2;
        
        if (currentLength > maxLength) {
            maxLength = currentLength;
            start = i - (currentLength - 1) / 2;
        }
    }
    
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';
    return result;
}

// Problem 12: Add Strings
// Add two numbers represented as strings
/**
 * Time Complexity: O(max(len(num1), len(num2)))
 * Space Complexity: O(max(len(num1), len(num2)))
 */
char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
    
    char* result = (char*)malloc((maxLen + 2) * sizeof(char));
    int i = len1 - 1;
    int j = len2 - 1;
    int k = maxLen;
    int carry = 0;
    
    result[maxLen + 1] = '\0';
    
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        
        int total = digit1 + digit2 + carry;
        carry = total / 10;
        result[k] = (total % 10) + '0';
        
        i--;
        j--;
        k--;
    }
    
    return result + k + 1;
}

// Problem 13: Multiply Strings
// Multiply two numbers represented as strings
/**
 * Time Complexity: O(m * n)
 * Space Complexity: O(m + n)
 */
char* multiplyStrings(char* num1, char* num2) {
    if (*num1 == '0' || *num2 == '0') {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    
    int m = strlen(num1);
    int n = strlen(num2);
    int* result = (int*)calloc(m + n, sizeof(int));
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int total = mul + result[p2];
            
            result[p2] = total % 10;
            result[p1] += total / 10;
        }
    }
    
    int start = 0;
    while (start < m + n && result[start] == 0) {
        start++;
    }
    
    char* strResult = (char*)malloc((m + n - start + 1) * sizeof(char));
    int idx = 0;
    for (int i = start; i < m + n; i++) {
        strResult[idx++] = result[i] + '0';
    }
    strResult[idx] = '\0';
    
    free(result);
    return strResult;
}

// Helper function to print string
void printString(char* s) {
    printf("\"%s\"", s);
}

// Test cases
int main() {
    printf("Problem 1 - Reverse String:\n");
    char str1[] = "hello";
    reverseString(str1, strlen(str1));
    printf("Reversed: %s\n", str1); // Output: "olleh"
    
    printf("\nProblem 2 - Valid Anagram:\n");
    printf("%s\n", isAnagram("anagram", "nagaram") ? "true" : "false"); // Output: true
    
    printf("\nProblem 3 - First Unique Character:\n");
    printf("%d\n", firstUniqChar("leetcode")); // Output: 0
    
    printf("\nProblem 4 - Valid Palindrome:\n");
    char str4[] = "A man, a plan, a canal: Panama";
    printf("%s\n", isPalindrome(str4) ? "true" : "false"); // Output: true
    
    printf("\nProblem 5 - Longest Common Prefix:\n");
    char* strs[] = {"flower", "flow", "flight"};
    char* prefix = longestCommonPrefix(strs, 3);
    printf("%s\n", prefix); // Output: "fl"
    free(prefix);
    
    printf("\nProblem 6 - String to Integer:\n");
    printf("%d\n", myAtoi("   -42")); // Output: -42
    
    printf("\nProblem 7 - Find Needle in Haystack:\n");
    printf("%d\n", strStr("hello", "ll")); // Output: 2
    
    printf("\nProblem 8 - Reverse Words:\n");
    char str8[] = "the sky is blue";
    reverseWords(str8);
    printf("%s\n", str8); // Output: "blue is sky the"
    
    printf("\nProblem 9 - Longest Substring Without Repeating Characters:\n");
    printf("%d\n", lengthOfLongestSubstring("abcabcbb")); // Output: 3
    
    printf("\nProblem 10 - Valid Parentheses:\n");
    printf("%s\n", isValidParentheses("()[]{}") ? "true" : "false"); // Output: true
    
    printf("\nProblem 11 - Longest Palindromic Substring:\n");
    char* palindrome = longestPalindrome("babad");
    printf("%s\n", palindrome); // Output: "bab" or "aba"
    free(palindrome);
    
    printf("\nProblem 12 - Add Strings:\n");
    char* sum = addStrings("123", "456");
    printf("%s\n", sum); // Output: "579"
    free(sum);
    
    printf("\nProblem 13 - Multiply Strings:\n");
    char* product = multiplyStrings("123", "456");
    printf("%s\n", product); // Output: "56088"
    free(product);
    
    return 0;
}
