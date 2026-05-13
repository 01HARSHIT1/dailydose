/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_eighty_two {

    // Problem 1: H-Index II
    // citations is sorted in ascending order. Return the researcher's h-index.

    /**
     * At index mid, compare citations[mid] with (n - mid), the count of papers from mid to end.
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static Integer hIndex(int[] citations) {
        if (citations == null || citations.length == 0) {
            return null;
        }

        int n = citations.length;
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int papersFromMid = n - mid;
            if (citations[mid] == papersFromMid) {
                return papersFromMid;
            }
            if (citations[mid] < papersFromMid) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return n - lo;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: H-Index II");
        System.out.println("=".repeat(60));

        int[] a = {0, 1, 3, 5, 6};
        System.out.println("[0,1,3,5,6] -> " + hIndex(a));

        int[] b = {1, 2, 100};
        System.out.println("[1,2,100] -> " + hIndex(b));

        int[] c = {1, 1, 2, 2, 2};
        System.out.println("[1,1,2,2,2] -> " + hIndex(c));

        int[] d = {0};
        System.out.println("[0] -> " + hIndex(d));

        System.out.println("null -> " + hIndex(null));
        System.out.println("empty -> " + hIndex(new int[0]));
    }
}
