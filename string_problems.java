import java.util.*;

/**
 * String DSA Interview Problems
 * Collection of common string problems with solutions
 */
public class string_problems {
    
    // Problem 1: Reverse String
    // Reverse a string in-place
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static String reverseString(String s) {
        char[] chars = s.toCharArray();
        int left = 0;
        int right = chars.length - 1;
        
        while (left < right) {
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;
            left++;
            right--;
        }
        
        return new String(chars);
    }
    
    // Problem 2: Valid Anagram
    // Check if two strings are anagrams
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1) - limited to 26 characters
     */
    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        Map<Character, Integer> charCount = new HashMap<>();
        for (char c : s.toCharArray()) {
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }
        
        for (char c : t.toCharArray()) {
            if (!charCount.containsKey(c)) {
                return false;
            }
            charCount.put(c, charCount.get(c) - 1);
            if (charCount.get(c) == 0) {
                charCount.remove(c);
            }
        }
        
        return charCount.isEmpty();
    }
    
    // Problem 3: First Unique Character
    // Find the first non-repeating character in a string
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1) - limited to 26 characters
     */
    public static int firstUniqChar(String s) {
        Map<Character, Integer> charCount = new HashMap<>();
        for (char c : s.toCharArray()) {
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (charCount.get(s.charAt(i)) == 1) {
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
    public static boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }
            
            if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
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
    public static String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        
        String prefix = strs[0];
        for (int i = 1; i < strs.length; i++) {
            while (!strs[i].startsWith(prefix)) {
                prefix = prefix.substring(0, prefix.length() - 1);
                if (prefix.isEmpty()) {
                    return "";
                }
            }
        }
        
        return prefix;
    }
    
    // Problem 6: String to Integer (atoi)
    // Convert string to integer
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int myAtoi(String s) {
        s = s.trim();
        if (s.isEmpty()) {
            return 0;
        }
        
        int sign = 1;
        if (s.charAt(0) == '-') {
            sign = -1;
            s = s.substring(1);
        } else if (s.charAt(0) == '+') {
            s = s.substring(1);
        }
        
        long result = 0;
        for (char c : s.toCharArray()) {
            if (!Character.isDigit(c)) {
                break;
            }
            result = result * 10 + (c - '0');
            if (result * sign > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if (result * sign < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
        }
        
        return (int)(result * sign);
    }
    
    // Problem 7: Implement strStr() (Find Needle in Haystack)
    // Find the first occurrence of needle in haystack
    /**
     * Time Complexity: O(n * m)
     * Space Complexity: O(1)
     */
    public static int strStr(String haystack, String needle) {
        if (needle.isEmpty()) {
            return 0;
        }
        
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack.substring(i, i + needle.length()).equals(needle)) {
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
    public static String reverseWords(String s) {
        String[] words = s.trim().split("\\s+");
        Collections.reverse(Arrays.asList(words));
        return String.join(" ", words);
    }
    
    // Problem 9: Longest Substring Without Repeating Characters
    // Find length of longest substring without repeating characters
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(min(n, m)) where m is charset size
     */
    public static int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> charMap = new HashMap<>();
        int maxLength = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            char c = s.charAt(end);
            if (charMap.containsKey(c) && charMap.get(c) >= start) {
                start = charMap.get(c) + 1;
            }
            
            charMap.put(c, end);
            maxLength = Math.max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
    
    // Problem 10: Group Anagrams
    // Group strings that are anagrams of each other
    /**
     * Time Complexity: O(n * k log k) where k is max string length
     * Space Complexity: O(n * k)
     */
    public static List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagramMap = new HashMap<>();
        
        for (String s : strs) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            
            if (!anagramMap.containsKey(sorted)) {
                anagramMap.put(sorted, new ArrayList<>());
            }
            anagramMap.get(sorted).add(s);
        }
        
        return new ArrayList<>(anagramMap.values());
    }
    
    // Problem 11: Minimum Window Substring
    // Find minimum window substring containing all characters of another string
    /**
     * Time Complexity: O(|s| + |t|)
     * Space Complexity: O(|s| + |t|)
     */
    public static String minWindow(String s, String t) {
        if (s.isEmpty() || t.isEmpty()) {
            return "";
        }
        
        Map<Character, Integer> dictT = new HashMap<>();
        for (char c : t.toCharArray()) {
            dictT.put(c, dictT.getOrDefault(c, 0) + 1);
        }
        
        int required = dictT.size();
        int left = 0, right = 0;
        int formed = 0;
        
        Map<Character, Integer> windowCounts = new HashMap<>();
        int[] ans = {-1, 0, 0};
        
        while (right < s.length()) {
            char c = s.charAt(right);
            windowCounts.put(c, windowCounts.getOrDefault(c, 0) + 1);
            
            if (dictT.containsKey(c) && windowCounts.get(c).intValue() == dictT.get(c).intValue()) {
                formed++;
            }
            
            while (left <= right && formed == required) {
                c = s.charAt(left);
                
                if (ans[0] == -1 || right - left + 1 < ans[0]) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }
                
                windowCounts.put(c, windowCounts.get(c) - 1);
                if (dictT.containsKey(c) && windowCounts.get(c).intValue() < dictT.get(c).intValue()) {
                    formed--;
                }
                
                left++;
            }
            
            right++;
        }
        
        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }
    
    // Problem 12: Longest Palindromic Substring
    // Find the longest palindromic substring
    /**
     * Time Complexity: O(n^2)
     * Space Complexity: O(1)
     */
    public static String longestPalindrome(String s) {
        if (s.isEmpty()) {
            return "";
        }
        
        int start = 0;
        int maxLength = 1;
        
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = Math.max(len1, len2);
            
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substring(start, start + maxLength);
    }
    
    private static int expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    
    // Problem 13: Valid Parentheses
    // Check if string contains valid parentheses
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static boolean isValidParentheses(String s) {
        Stack<Character> stack = new Stack<>();
        Map<Character, Character> mapping = new HashMap<>();
        mapping.put(')', '(');
        mapping.put('}', '{');
        mapping.put(']', '[');
        
        for (char c : s.toCharArray()) {
            if (mapping.containsKey(c)) {
                char topElement = stack.isEmpty() ? '#' : stack.pop();
                if (topElement != mapping.get(c)) {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        
        return stack.isEmpty();
    }
    
    // Problem 14: Count and Say
    // Generate the nth term of the count-and-say sequence
    /**
     * Time Complexity: O(2^n) approximately
     * Space Complexity: O(2^n) approximately
     */
    public static String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        String prev = countAndSay(n - 1);
        StringBuilder result = new StringBuilder();
        int count = 1;
        
        for (int i = 0; i < prev.length(); i++) {
            if (i < prev.length() - 1 && prev.charAt(i) == prev.charAt(i + 1)) {
                count++;
            } else {
                result.append(count).append(prev.charAt(i));
                count = 1;
            }
        }
        
        return result.toString();
    }
    
    // Problem 15: Remove Duplicate Letters
    // Remove duplicate letters to get lexicographically smallest result
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1) - limited to 26 characters
     */
    public static String removeDuplicateLetters(String s) {
        Map<Character, Integer> lastOccurrence = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence.put(s.charAt(i), i);
        }
        
        Stack<Character> stack = new Stack<>();
        Set<Character> seen = new HashSet<>();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (seen.contains(c)) {
                continue;
            }
            
            while (!stack.isEmpty() && c < stack.peek() && lastOccurrence.get(stack.peek()) > i) {
                seen.remove(stack.pop());
            }
            
            stack.push(c);
            seen.add(c);
        }
        
        StringBuilder result = new StringBuilder();
        for (char c : stack) {
            result.append(c);
        }
        
        return result.toString();
    }
    
    // Problem 16: Word Pattern
    // Check if string follows a given pattern
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) {
            return false;
        }
        
        Map<Character, String> patternToWord = new HashMap<>();
        Map<String, Character> wordToPattern = new HashMap<>();
        
        for (int i = 0; i < pattern.length(); i++) {
            char p = pattern.charAt(i);
            String word = words[i];
            
            if (patternToWord.containsKey(p)) {
                if (!patternToWord.get(p).equals(word)) {
                    return false;
                }
            } else {
                if (wordToPattern.containsKey(word)) {
                    return false;
                }
                patternToWord.put(p, word);
                wordToPattern.put(word, p);
            }
        }
        
        return true;
    }
    
    // Problem 17: Reverse String II
    // Reverse every k characters in a string
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static String reverseStr(String s, int k) {
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i += 2 * k) {
            int left = i;
            int right = Math.min(i + k - 1, chars.length - 1);
            
            while (left < right) {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
                left++;
                right--;
            }
        }
        
        return new String(chars);
    }
    
    // Problem 18: ZigZag Conversion
    // Convert string to zigzag pattern
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static String convertZigzag(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        List<StringBuilder> rows = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            rows.add(new StringBuilder());
        }
        
        int currentRow = 0;
        boolean goingDown = false;
        
        for (char c : s.toCharArray()) {
            rows.get(currentRow).append(c);
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }
        
        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }
        
        return result.toString();
    }
    
    // Problem 19: Add Strings
    // Add two numbers represented as strings
    /**
     * Time Complexity: O(max(len(num1), len(num2)))
     * Space Complexity: O(max(len(num1), len(num2)))
     */
    public static String addStrings(String num1, String num2) {
        StringBuilder result = new StringBuilder();
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry != 0) {
            int digit1 = i >= 0 ? num1.charAt(i) - '0' : 0;
            int digit2 = j >= 0 ? num2.charAt(j) - '0' : 0;
            
            int total = digit1 + digit2 + carry;
            carry = total / 10;
            result.append(total % 10);
            
            i--;
            j--;
        }
        
        return result.reverse().toString();
    }
    
    // Problem 20: Multiply Strings
    // Multiply two numbers represented as strings
    /**
     * Time Complexity: O(m * n)
     * Space Complexity: O(m + n)
     */
    public static String multiplyStrings(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        
        int m = num1.length();
        int n = num2.length();
        int[] result = new int[m + n];
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                int p1 = i + j;
                int p2 = i + j + 1;
                int total = mul + result[p2];
                
                result[p2] = total % 10;
                result[p1] += total / 10;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        int start = 0;
        while (start < result.length && result[start] == 0) {
            start++;
        }
        
        for (int i = start; i < result.length; i++) {
            sb.append(result[i]);
        }
        
        return sb.toString();
    }
    
    // Helper method to print list of lists
    private static void printListOfLists(List<List<String>> lists) {
        System.out.print("[");
        for (int i = 0; i < lists.size(); i++) {
            System.out.print(lists.get(i));
            if (i < lists.size() - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("Problem 1 - Reverse String:");
        System.out.println(reverseString("hello")); // Output: "olleh"
        
        System.out.println("\nProblem 2 - Valid Anagram:");
        System.out.println(isAnagram("anagram", "nagaram")); // Output: true
        
        System.out.println("\nProblem 3 - First Unique Character:");
        System.out.println(firstUniqChar("leetcode")); // Output: 0
        
        System.out.println("\nProblem 4 - Valid Palindrome:");
        System.out.println(isPalindrome("A man, a plan, a canal: Panama")); // Output: true
        
        System.out.println("\nProblem 5 - Longest Common Prefix:");
        System.out.println(longestCommonPrefix(new String[]{"flower", "flow", "flight"})); // Output: "fl"
        
        System.out.println("\nProblem 6 - String to Integer:");
        System.out.println(myAtoi("   -42")); // Output: -42
        
        System.out.println("\nProblem 7 - Find Needle in Haystack:");
        System.out.println(strStr("hello", "ll")); // Output: 2
        
        System.out.println("\nProblem 8 - Reverse Words:");
        System.out.println(reverseWords("the sky is blue")); // Output: "blue is sky the"
        
        System.out.println("\nProblem 9 - Longest Substring Without Repeating Characters:");
        System.out.println(lengthOfLongestSubstring("abcabcbb")); // Output: 3
        
        System.out.println("\nProblem 10 - Group Anagrams:");
        printListOfLists(groupAnagrams(new String[]{"eat", "tea", "tan", "ate", "nat", "bat"}));
        
        System.out.println("\nProblem 11 - Minimum Window Substring:");
        System.out.println(minWindow("ADOBECODEBANC", "ABC")); // Output: "BANC"
        
        System.out.println("\nProblem 12 - Longest Palindromic Substring:");
        System.out.println(longestPalindrome("babad")); // Output: "bab" or "aba"
        
        System.out.println("\nProblem 13 - Valid Parentheses:");
        System.out.println(isValidParentheses("()[]{}")); // Output: true
        
        System.out.println("\nProblem 14 - Count and Say:");
        System.out.println(countAndSay(4)); // Output: "1211"
        
        System.out.println("\nProblem 15 - Remove Duplicate Letters:");
        System.out.println(removeDuplicateLetters("bcabc")); // Output: "abc"
        
        System.out.println("\nProblem 16 - Word Pattern:");
        System.out.println(wordPattern("abba", "dog cat cat dog")); // Output: true
        
        System.out.println("\nProblem 17 - Reverse String II:");
        System.out.println(reverseStr("abcdefg", 2)); // Output: "bacdfeg"
        
        System.out.println("\nProblem 18 - ZigZag Conversion:");
        System.out.println(convertZigzag("PAYPALISHIRING", 3)); // Output: "PAHNAPLSIIGYIR"
        
        System.out.println("\nProblem 19 - Add Strings:");
        System.out.println(addStrings("123", "456")); // Output: "579"
        
        System.out.println("\nProblem 20 - Multiply Strings:");
        System.out.println(multiplyStrings("123", "456")); // Output: "56088"
    }
}
