/**
 * Basic DSA Problems - Two Fundamental Questions
 */
public class basic_dsa_thirteen {

    // Problem 1: Find Largest of Three Numbers
    // Return the largest among a, b, c
    /**
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static int largestOfThree(int a, int b, int c) {
        if (a >= b && a >= c) return a;
        if (b >= a && b >= c) return b;
        return c;
    }

    // Problem 2: Check if a Year is a Leap Year
    // Leap year rules:
    // - divisible by 400 => leap
    // - divisible by 100 => not leap
    // - divisible by 4 => leap
    /**
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    public static boolean isLeapYear(int year) {
        if (year % 400 == 0) return true;
        if (year % 100 == 0) return false;
        return year % 4 == 0;
    }

    public static void main(String[] args) {
        System.out.println("Problem 1 - Largest of Three Numbers:");
        System.out.println(largestOfThree(10, 20, 5));   // 20
        System.out.println(largestOfThree(-1, -5, -3));  // -1
        System.out.println(largestOfThree(7, 7, 2));     // 7

        System.out.println("\nProblem 2 - Leap Year Check:");
        int[] years = {1900, 2000, 2024, 2023};
        for (int y : years) {
            System.out.println(y + " => " + isLeapYear(y));
        }
    }
}

