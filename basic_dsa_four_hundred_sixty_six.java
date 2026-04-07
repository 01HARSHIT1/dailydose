/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_sixty_six {

    // Problem 1: Best Time to Buy and Sell Stock
    // Given an array prices where prices[i] is the price of a stock on day i,
    // return the maximum profit you can achieve from one buy and one sell.
    // You must buy before you sell.
    //
    // Example:
    // prices = [7,1,5,3,6,4] -> 5 (buy at 1, sell at 6)

    /**
     * Track minimum price so far; maximize (price - minPrice)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return null;
        }
        if (prices.length == 1) {
            return 0;
        }

        int minPrice = prices[0];
        int best = 0;

        for (int i = 1; i < prices.length; i++) {
            int p = prices[i];
            best = Math.max(best, p - minPrice);
            minPrice = Math.min(minPrice, p);
        }

        return best;
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

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Best Time to Buy and Sell Stock");
        System.out.println("=".repeat(60));

        int[] p1 = {7, 1, 5, 3, 6, 4};
        System.out.println("Prices: " + arrayToString(p1));
        System.out.println("Max profit: " + maxProfit(p1));

        int[] p2 = {7, 6, 4, 3, 1};
        System.out.println("\nPrices: " + arrayToString(p2));
        System.out.println("Max profit: " + maxProfit(p2));

        int[] p3 = {2, 4, 1};
        System.out.println("\nPrices: " + arrayToString(p3));
        System.out.println("Max profit: " + maxProfit(p3));

        int[] p4 = {5};
        System.out.println("\nPrices: " + arrayToString(p4));
        System.out.println("Max profit: " + maxProfit(p4));

        int[] p5 = {};
        System.out.println("\nPrices: " + arrayToString(p5));
        System.out.println("Max profit: " + maxProfit(p5));

        System.out.println("\nPrices: null");
        System.out.println("Max profit: " + maxProfit(null));
    }
}
