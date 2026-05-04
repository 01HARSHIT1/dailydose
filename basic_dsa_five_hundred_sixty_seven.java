/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_sixty_seven {

    // Problem 1: Guess Number Higher or Lower
    // We pick a number from 1 to n. You have to guess which number is picked.
    // Every guess returns:
    // -1 if guess is higher than picked number
    //  1 if guess is lower than picked number
    //  0 if guess is correct
    //
    // Return the picked number.

    // Demo stub to simulate the guess API locally.
    private static int picked = 6;
    private static int guess(int num) {
        if (num == picked) {
            return 0;
        }
        return num > picked ? -1 : 1;
    }

    /**
     * Binary search over [1, n]
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static Integer guessNumber(int n) {
        if (n <= 0) {
            return null;
        }

        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);
            if (result == 0) {
                return mid;
            } else if (result < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return null;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Guess Number Higher or Lower");
        System.out.println("=".repeat(60));

        picked = 6;
        System.out.println("n = 10, picked = 6 -> " + guessNumber(10));

        picked = 1;
        System.out.println("n = 1, picked = 1 -> " + guessNumber(1));

        picked = 42;
        System.out.println("n = 100, picked = 42 -> " + guessNumber(100));

        System.out.println("n = 0 -> " + guessNumber(0));
        System.out.println("n = -5 -> " + guessNumber(-5));
    }
}
