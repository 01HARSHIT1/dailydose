/**
 * Basic DSA Problems - One Fundamental Greedy Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_eighty_six {

    // Problem 1: Can Place Flowers
    // You have a long flowerbed with plots (0 = empty, 1 = planted).
    // Flowers cannot be planted in adjacent plots. Given flowerbed and n,
    // return true if n new flowers can be planted without violating the rule.
    //
    // Example:
    // flowerbed = [1,0,0,0,1], n = 1 -> true

    /**
     * Greedy: place when neighbors are empty (edge counts as empty)
     * Time Complexity: O(m)
     * Space Complexity: O(1)
     */
    public static Boolean canPlaceFlowers(int[] flowerbed, int n) {
        if (flowerbed == null || n < 0) {
            return null;
        }
        if (n == 0) {
            return true;
        }

        int count = 0;
        int len = flowerbed.length;
        for (int i = 0; i < len; i++) {
            if (flowerbed[i] == 1) {
                continue;
            }
            boolean leftEmpty = i == 0 || flowerbed[i - 1] == 0;
            boolean rightEmpty = i == len - 1 || flowerbed[i + 1] == 0;
            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                count++;
                if (count >= n) {
                    return true;
                }
            }
        }
        return count >= n;
    }

    private static String arrayToString(int[] arr) {
        if (arr == null) {
            return "null";
        }
        if (arr.length == 0) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases (use copies so main does not mutate shared arrays across prints)
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Can Place Flowers");
        System.out.println("=".repeat(60));

        int[] a = {1, 0, 0, 0, 1};
        System.out.println("bed=" + arrayToString(a) + ", n=1 -> " + canPlaceFlowers(a.clone(), 1));

        int[] b = {1, 0, 0, 0, 1};
        System.out.println("bed=" + arrayToString(b) + ", n=2 -> " + canPlaceFlowers(b.clone(), 2));

        int[] c = {0, 0, 1, 0, 0};
        System.out.println("bed=" + arrayToString(c) + ", n=1 -> " + canPlaceFlowers(c.clone(), 1));

        int[] d = {0};
        System.out.println("bed=[0], n=1 -> " + canPlaceFlowers(d.clone(), 1));

        System.out.println("bed=null, n=1 -> " + canPlaceFlowers(null, 1));
    }
}
