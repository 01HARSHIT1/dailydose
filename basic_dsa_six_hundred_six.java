/**
 * Basic DSA Problems - One Fundamental Three-Way Partition Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_six {

    // Problem 1: Sort Colors (Dutch National Flag)
    // nums contains only 0, 1, and 2. Sort them in-place so all 0s, then 1s, then 2s.

    /**
     * Three pointers: low, mid, high — one pass
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void sortColors(int[] nums) {
        if (nums == null || nums.length == 0) {
            return;
        }

        int low = 0;
        int mid = 0;
        int high = nums.length - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums, low, mid);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums, mid, high);
                high--;
            }
        }
    }

    private static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
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

    private static int[] cloneCopy(int[] src) {
        if (src == null) {
            return null;
        }
        int[] c = new int[src.length];
        System.arraycopy(src, 0, c, 0, src.length);
        return c;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Sort Colors");
        System.out.println("=".repeat(60));

        int[] a = {2, 0, 2, 1, 1, 0};
        int[] ac = cloneCopy(a);
        sortColors(ac);
        System.out.println("sample -> " + arrToString(ac));

        int[] b = {2, 0, 1};
        sortColors(b);
        System.out.println("[2,0,1] -> " + arrToString(b));

        int[] c = {1};
        sortColors(c);
        System.out.println("[1] -> " + arrToString(c));

        sortColors(null);
        System.out.println("null (no throw) ok");
    }
}
