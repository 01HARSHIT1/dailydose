/**
 * Basic DSA Problems - Best Time to Buy and Sell Stock
 * Maximum profit from one buy and one sell
 */
public class basic_dsa_one_hundred_seventeen {

    // Problem: Given array where prices[i] is stock price on day i, find maximum profit from
    // at most one buy and one sell (buy before sell). Return 0 if no profit possible.

    /**
     * Track minimum price seen so far; at each day profit = price - min, update max profit.
     * Time O(n), Space O(1)
     */
    public static int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2) return 0;
        int minPrice = prices[0], maxProfit = 0;
        for (int i = 1; i < prices.length; i++) {
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);
            minPrice = Math.min(minPrice, prices[i]);
        }
        return maxProfit;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Best Time to Buy and Sell Stock");
        System.out.println("=".repeat(60));

        System.out.println("[7,1,5,3,6,4] -> " + maxProfit(new int[] { 7, 1, 5, 3, 6, 4 }));
        System.out.println("[7,6,4,3,1] -> " + maxProfit(new int[] { 7, 6, 4, 3, 1 }));
    }
}
