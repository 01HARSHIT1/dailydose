/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_twenty_six {

    // Problem 1: Best Time to Buy and Sell Stock
    // You are given an array prices where prices[i] is the price of a given stock on day i.
    // You want to maximize your profit by choosing a single day to buy one stock and choosing
    // a different day in the future to sell that stock.
    //
    // Return the maximum profit you can achieve from this transaction.
    // If you cannot achieve any profit, return 0.
    //
    // Example:
    // prices = [7,1,5,3,6,4] -> 5

    /**
     * Track minimum seen so far and best profit
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer maxProfit(int[] prices) {
        if (prices == null) {
            return null;
        }
        if (prices.length == 0) {
            return 0;
        }

        int minPrice = prices[0];
        int bestProfit = 0;

        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                int profit = prices[i] - minPrice;
                if (profit > bestProfit) {
                    bestProfit = profit;
                }
            }
        }

        return bestProfit;
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

        int[] prices1 = {7, 1, 5, 3, 6, 4};
        System.out.println("prices = " + arrayToString(prices1) + " -> " + maxProfit(prices1));

        int[] prices2 = {7, 6, 4, 3, 1};
        System.out.println("prices = " + arrayToString(prices2) + " -> " + maxProfit(prices2));

        int[] prices3 = {2, 4, 1};
        System.out.println("prices = " + arrayToString(prices3) + " -> " + maxProfit(prices3));

        int[] prices4 = {};
        System.out.println("prices = " + arrayToString(prices4) + " -> " + maxProfit(prices4));

        System.out.println("prices = null -> " + maxProfit(null));
    }
}
