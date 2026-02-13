/**
 * Basic DSA Problems - Add Digits
 * Digital root: repeatedly add digits until single digit
 */
public class basic_dsa_two_hundred_sixty_two {

    // Problem: Given num, repeatedly add its digits until single digit. Return result.
    // Example: 38 -> 3+8=11 -> 1+1=2.

    /**
     * Digital root: result is 0 if num==0, else 1 + (num-1)%9.
     * Time O(1), Space O(1)
     */
    public static int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Add Digits");
        System.out.println("=".repeat(60));

        System.out.println("38 -> " + addDigits(38));
        System.out.println("0 -> " + addDigits(0));
        System.out.println("123 -> " + addDigits(123));
    }
}
