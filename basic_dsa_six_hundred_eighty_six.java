/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_eighty_six {

    // Problem 1: Kth Missing Positive Integer
    // arr is sorted with distinct positive integers; return k-th positive integer not in arr.

    /**
     * Missing count strictly before arr[i] equals arr[i] - i - 1.
     * First index with missing count >= k bounds the answer at k + that index.
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static Integer findKthPositive(int[] arr, int k) {
        if (k < 1) {
            return null;
        }
        if (arr == null) {
            return null;
        }
        if (arr.length == 0) {
            return k;
        }

        int lo = 0;
        int hi = arr.length;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] - mid - 1 < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return lo + k;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Kth Missing Positive Integer");
        System.out.println("=".repeat(60));

        int[] a = {2, 3, 4, 7, 11};
        System.out.println("[2,3,4,7,11], k=5 -> " + findKthPositive(a, 5));

        int[] b = {1, 2, 3, 4};
        System.out.println("[1,2,3,4], k=2 -> " + findKthPositive(b, 2));

        int[] c = {5, 6, 7, 8, 9};
        System.out.println("[5,6,7,8,9], k=9 -> " + findKthPositive(c, 9));

        System.out.println("empty, k=7 -> " + findKthPositive(new int[0], 7));

        int[] d = {3};
        System.out.println("[3], k=1 -> " + findKthPositive(d, 1));

        System.out.println("null -> " + findKthPositive(null, 1));
        System.out.println("k=0 -> " + findKthPositive(a, 0));
    }
}
