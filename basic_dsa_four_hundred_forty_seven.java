/**
 * Basic DSA Problems - Number of Boomerangs (LeetCode 447)
 * (i,j,k) boomerang: dist(i,j) = dist(i,k). Order matters.
 */
public class basic_dsa_four_hundred_forty_seven {

    // Problem: n points. Count tuples (i,j,k) where dist(i,j)=dist(i,k), j!=k.

    /**
     * For each point i as center, count distances to others. c*(c-1) per distance.
     * Use squared distance to avoid float. Time O(n^2), Space O(n)
     */
    public static int numberOfBoomerangs(int[][] points) {
        int n = points.length, ans = 0;
        for (int i = 0; i < n; i++) {
            java.util.Map<Long, Integer> cnt = new java.util.HashMap<>();
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long dx = points[i][0] - points[j][0];
                long dy = points[i][1] - points[j][1];
                long d = dx * dx + dy * dy;
                cnt.put(d, cnt.getOrDefault(d, 0) + 1);
            }
            for (int c : cnt.values()) ans += c * (c - 1);
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Number of Boomerangs");
        System.out.println("=".repeat(60));

        System.out.println("[[0,0],[1,0],[2,0]] -> " + numberOfBoomerangs(new int[][]{{0,0},{1,0},{2,0}}));
        System.out.println("[[1,1],[2,2],[3,3]] -> " + numberOfBoomerangs(new int[][]{{1,1},{2,2},{3,3}}));
    }
}
