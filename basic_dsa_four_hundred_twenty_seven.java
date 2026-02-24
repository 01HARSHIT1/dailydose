/**
 * Basic DSA Problems - Construct Quad Tree (LeetCode 427)
 * Build quad tree from n*n grid of 0s and 1s. Split until uniform.
 */
public class basic_dsa_four_hundred_twenty_seven {

    static class Node {
        boolean val;
        boolean isLeaf;
        Node topLeft, topRight, bottomLeft, bottomRight;
        Node(boolean v, boolean leaf) { val = v; isLeaf = leaf; }
    }

    /**
     * Recursive: if region uniform -> leaf. Else split into 4 quadrants.
     * Time O(n^2 log n), Space O(log n)
     */
    public static Node construct(int[][] grid) {
        return dfs(0, 0, grid.length - 1, grid[0].length - 1, grid);
    }

    private static Node dfs(int a, int b, int c, int d, int[][] grid) {
        int zero = 0, one = 0;
        for (int i = a; i <= c; i++)
            for (int j = b; j <= d; j++)
                if (grid[i][j] == 0) zero = 1; else one = 1;
        boolean isLeaf = zero + one == 1;
        boolean val = isLeaf && one == 1;
        Node node = new Node(val, isLeaf);
        if (isLeaf) return node;
        int midR = (a + c) / 2, midC = (b + d) / 2;
        node.topLeft = dfs(a, b, midR, midC, grid);
        node.topRight = dfs(a, midC + 1, midR, d, grid);
        node.bottomLeft = dfs(midR + 1, b, c, midC, grid);
        node.bottomRight = dfs(midR + 1, midC + 1, c, d, grid);
        return node;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Construct Quad Tree");
        System.out.println("=".repeat(60));

        int[][] g1 = {{0,1},{1,0}};
        Node r1 = construct(g1);
        System.out.println("[[0,1],[1,0]] -> root isLeaf=" + r1.isLeaf + " val=" + r1.val);

        int[][] g2 = {{1,1},{1,1}};
        Node r2 = construct(g2);
        System.out.println("[[1,1],[1,1]] -> leaf val=" + r2.val + " isLeaf=" + r2.isLeaf);

        int[][] g3 = {{1,1,0,0},{1,1,0,0},{0,0,1,1},{0,0,1,1}};
        Node r3 = construct(g3);
        System.out.println("4x4 grid -> root isLeaf=" + r3.isLeaf);
    }
}
