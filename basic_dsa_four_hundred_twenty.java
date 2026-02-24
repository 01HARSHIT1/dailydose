/**
 * Basic DSA Problems - Strong Password Checker (LeetCode 420)
 * Min steps to make password strong: 6-20 chars, lower+upper+digit, no 3+ repeats
 */
public class basic_dsa_four_hundred_twenty {

    // Problem: insert/delete/replace. Need 6-20 len, 3 types, no "aaa".

    private static int countTypes(String s) {
        int a = 0, b = 0, c = 0;
        for (char ch : s.toCharArray()) {
            if (Character.isLowerCase(ch)) a = 1;
            else if (Character.isUpperCase(ch)) b = 1;
            else if (Character.isDigit(ch)) c = 1;
        }
        return a + b + c;
    }

    /**
     * Cases: len<6, 6-20, >20. Use deletions strategically when len>20.
     * Time O(n), Space O(1)
     */
    public static int strongPasswordChecker(String password) {
        int types = countTypes(password);
        int n = password.length();
        if (n < 6) return Math.max(6 - n, 3 - types);
        char[] chars = password.toCharArray();
        if (n <= 20) {
            int replace = 0, cnt = 0;
            char prev = '~';
            for (char curr : chars) {
                if (curr == prev) ++cnt;
                else { replace += cnt / 3; cnt = 1; prev = curr; }
            }
            replace += cnt / 3;
            return Math.max(replace, 3 - types);
        }
        int replace = 0, remove = n - 20, remove2 = 0, cnt = 0;
        char prev = '~';
        for (char curr : chars) {
            if (curr == prev) ++cnt;
            else {
                if (remove > 0 && cnt >= 3) {
                    if (cnt % 3 == 0) { remove--; replace--; }
                    else if (cnt % 3 == 1) remove2++;
                }
                replace += cnt / 3; cnt = 1; prev = curr;
            }
        }
        if (remove > 0 && cnt >= 3) {
            if (cnt % 3 == 0) { remove--; replace--; }
            else if (cnt % 3 == 1) remove2++;
        }
        replace += cnt / 3;
        int use2 = Math.min(Math.min(replace, remove2), remove / 2);
        replace -= use2; remove -= use2 * 2;
        int use3 = Math.min(replace, remove / 3);
        replace -= use3; remove -= use3 * 3;
        return (n - 20) + Math.max(replace, 3 - types);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Strong Password Checker");
        System.out.println("=".repeat(60));

        System.out.println("\"a\" -> " + strongPasswordChecker("a"));
        System.out.println("\"aA1\" -> " + strongPasswordChecker("aA1"));
        System.out.println("\"1337C0d3\" -> " + strongPasswordChecker("1337C0d3"));
        System.out.println("\"aaabbb\" -> " + strongPasswordChecker("aaabbb"));
    }
}
