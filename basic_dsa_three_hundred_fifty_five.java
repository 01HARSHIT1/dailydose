/**
 * Basic DSA Problems - Design Twitter (LeetCode 355)
 * postTweet, getNewsFeed, follow, unfollow
 */
public class basic_dsa_three_hundred_fifty_five {

    // Problem: postTweet(userId, tweetId), getNewsFeed(userId)->10 recent, follow/unfollow.

    static class Twitter {
        int time = 0;
        java.util.Map<Integer, java.util.Set<Integer>> following = new java.util.HashMap<>();
        java.util.Map<Integer, java.util.List<int[]>> tweets = new java.util.HashMap<>();

        public void postTweet(int userId, int tweetId) {
            tweets.computeIfAbsent(userId, k -> new java.util.ArrayList<>()).add(new int[]{time++, tweetId});
        }

        public java.util.List<Integer> getNewsFeed(int userId) {
            java.util.PriorityQueue<int[]> pq = new java.util.PriorityQueue<>((a, b) -> b[0] - a[0]);
            java.util.Set<Integer> users = new java.util.HashSet<>();
            users.add(userId);
            if (following.containsKey(userId)) users.addAll(following.get(userId));
            for (int u : users)
                if (tweets.containsKey(u))
                    for (int[] t : tweets.get(u)) pq.offer(t);
            java.util.List<Integer> out = new java.util.ArrayList<>();
            for (int i = 0; i < 10 && !pq.isEmpty(); i++) out.add(pq.poll()[1]);
            return out;
        }

        public void follow(int followerId, int followeeId) {
            if (followerId != followeeId)
                following.computeIfAbsent(followerId, k -> new java.util.HashSet<>()).add(followeeId);
        }

        public void unfollow(int followerId, int followeeId) {
            if (following.containsKey(followerId)) following.get(followerId).remove(followeeId);
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Design Twitter");
        System.out.println("=".repeat(60));

        Twitter t = new Twitter();
        t.postTweet(1, 5);
        System.out.println("postTweet(1,5), getNewsFeed(1) -> " + t.getNewsFeed(1));
        t.follow(1, 2);
        t.postTweet(2, 6);
        System.out.println("follow(1,2), postTweet(2,6), getNewsFeed(1) -> " + t.getNewsFeed(1));
    }
}
