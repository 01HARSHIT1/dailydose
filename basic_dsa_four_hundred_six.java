/**
 * Basic DSA Problems - Queue Reconstruction by Height (LeetCode 406)
 * people[i]=[h,k]: k people in front with height>=h. Reconstruct queue.
 */
public class basic_dsa_four_hundred_six {

    // Problem: [h,k] - k = count of people in front with height >= h.

    /**
     * Sort by h descending, k ascending. Insert each at index k.
     * Time O(n^2), Space O(n)
     */
    public static int[][] reconstructQueue(int[][] people) {
        java.util.Arrays.sort(people, (a, b) -> a[0] != b[0] ? b[0] - a[0] : a[1] - b[1]);
        java.util.List<int[]> list = new java.util.ArrayList<>();
        for (int[] p : people) list.add(p[1], p);
        return list.toArray(new int[0][]);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Queue Reconstruction by Height");
        System.out.println("=".repeat(60));

        int[][] people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
        System.out.println("Result: " + java.util.Arrays.deepToString(reconstructQueue(people)));
    }
}
