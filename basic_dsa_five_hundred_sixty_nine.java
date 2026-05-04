/**
 * Basic DSA Problems - One Fundamental Queue/Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_sixty_nine {

    // Problem 1: Number of Recent Calls
    // Implement a class RecentCounter to count recent requests within the last 3000 ms.
    //
    // recentCounter.ping(t) adds a new request at time t (milliseconds),
    // and returns the number of requests where time is in [t - 3000, t].

    static class RecentCounter {
        private final java.util.ArrayDeque<Integer> q = new java.util.ArrayDeque<>();

        /**
         * Queue sliding window of timestamps
         * Time Complexity: Amortized O(1)
         * Space Complexity: O(n) for requests in current window
         */
        public int ping(int t) {
            q.offer(t);
            while (!q.isEmpty() && q.peek() < t - 3000) {
                q.poll();
            }
            return q.size();
        }
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Number of Recent Calls");
        System.out.println("=".repeat(60));

        RecentCounter rc = new RecentCounter();
        System.out.println("ping(1) -> " + rc.ping(1));       // 1
        System.out.println("ping(100) -> " + rc.ping(100));   // 2
        System.out.println("ping(3001) -> " + rc.ping(3001)); // 3
        System.out.println("ping(3002) -> " + rc.ping(3002)); // 3
        System.out.println("ping(7000) -> " + rc.ping(7000)); // 1
    }
}
