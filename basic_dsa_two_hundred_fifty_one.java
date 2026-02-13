/**
 * Basic DSA Problems - Number of Boomerangs
 * Count tuples (i, j, k) where dist(i,j) = dist(i,k)
 */
public class basic_dsa_two_hundred_fifty_one {

    // Problem: points[i] = [xi, yi]. Boomerang: (i, j, k) with dist(i,j) = dist(i,k), j != k.
    // Return total number of boomerangs.

    /**
     * For each point i, count distances to all others. For each distance d with count c,
     * boomerangs = c * (c-1). Sum over all i.
     * Time O(n^2), Space O(n)
     */
    public static int numberOfBoomerangs(int[][] points) {
        int count = 0;
        for (int i = 0; i < points.length; i++) {
            java.util.Map<Integer, Integer> distCount = new java.util.HashMap<>();
            for (int j = 0; j < points.length; j++) {
                if (i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int d = dx * dx + dy * dy;
                distCount.put(d, distCount.getOrDefault(d, 0) + 1);
            }
            for (int c : distCount.values())
                count += c * (c - 1);
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Number of Boomerangs");
        System.out.println("=".repeat(60));

        System.out.println("[[0,0],[1,0],[2,0]] -> " + numberOfBoomerangs(new int[][]{{0, 0}, {1, 0}, {2, 0}}));
        System.out.println("[[1,1],[2,2],[3,3]] -> " + numberOfBoomerangs(new int[][]{{1, 1}, {2, 2}, {3, 3}}));
    }
}
