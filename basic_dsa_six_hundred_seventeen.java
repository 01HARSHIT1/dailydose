/**
 * Basic DSA Problems - One Fundamental Array Rotation Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_seventeen {

    // Problem 1: Rotate Array
    // Rotate nums to the right by k steps (non-negative); return a new array.

    /**
     * Index map: new[(i + k) % n] = old[i] after normalizing k %= n
     * Time Complexity: O(n)
     * Space Complexity: O(n) for the output array
     */
    public static int[] rotateRight(int[] nums, int k) {
        if (nums == null) {
            return null;
        }

        int n = nums.length;
        if (n == 0) {
            return new int[0];
        }

        int kk = k % n;
        if (kk < 0) {
            kk = (kk + n) % n;
        }

        int[] out = new int[n];
        for (int i = 0; i < n; i++) {
            out[(i + kk) % n] = nums[i];
        }
        return out;
    }

    private static String arrToString(int[] a) {
        if (a == null) {
            return "null";
        }
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(a[i]);
        }
        return sb.append("]").toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Rotate Array");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 3, 4, 5};
        System.out.println("k=2 -> " + arrToString(rotateRight(a, 2)));

        int[] b = {-1, -100, 3, 99};
        System.out.println("k=2 -> " + arrToString(rotateRight(b, 2)));

        int[] c = {1};
        System.out.println("k=3 -> " + arrToString(rotateRight(c, 3)));

        System.out.println("null -> " + arrToString(rotateRight(null, 1)));
        System.out.println("empty -> " + arrToString(rotateRight(new int[0], 5)));
    }
}
