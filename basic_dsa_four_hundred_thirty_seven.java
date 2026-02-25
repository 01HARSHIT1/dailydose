/**
 * Basic DSA Problems - Path Sum III (LeetCode 437)
 * Count paths (any start/end, downward only) that sum to target
 */
public class basic_dsa_four_hundred_thirty_seven {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int v) { val = v; }
    }

    // Problem: paths downward summing to target. Prefix-sum map.

    /**
     * Prefix sum: cnt[sum]=count. At node: ans += cnt[s-target]; cnt[s]++; recurse; cnt[s]--.
     * Time O(n), Space O(n)
     */
    public static int pathSum(TreeNode root, int targetSum) {
        java.util.Map<Long, Integer> cnt = new java.util.HashMap<>();
        cnt.put(0L, 1);
        return dfs(root, 0L, targetSum, cnt);
    }

    private static int dfs(TreeNode node, long s, int target, java.util.Map<Long, Integer> cnt) {
        if (node == null) return 0;
        s += node.val;
        int ans = cnt.getOrDefault(s - target, 0);
        cnt.put(s, cnt.getOrDefault(s, 0) + 1);
        ans += dfs(node.left, s, target, cnt);
        ans += dfs(node.right, s, target, cnt);
        cnt.put(s, cnt.get(s) - 1);
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Path Sum III");
        System.out.println("=".repeat(60));

        TreeNode r = new TreeNode(10);
        r.left = new TreeNode(5); r.right = new TreeNode(-3);
        r.left.left = new TreeNode(3); r.left.right = new TreeNode(2);
        r.right.right = new TreeNode(11);
        r.left.left.left = new TreeNode(3); r.left.left.right = new TreeNode(-2);
        r.left.right.right = new TreeNode(1);
        System.out.println("target=8 -> " + pathSum(r, 8));

        TreeNode r2 = new TreeNode(5);
        r2.left = new TreeNode(4); r2.right = new TreeNode(8);
        r2.left.left = new TreeNode(11);
        r2.left.left.left = new TreeNode(7); r2.left.left.right = new TreeNode(2);
        r2.right.left = new TreeNode(13); r2.right.right = new TreeNode(4);
        r2.right.right.left = new TreeNode(5); r2.right.right.right = new TreeNode(1);
        System.out.println("target=22 -> " + pathSum(r2, 22));
    }
}
