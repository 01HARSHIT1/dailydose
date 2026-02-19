/**
 * Basic DSA Problems - Design Hit Counter (LeetCode 362)
 * hit(timestamp), getHits(timestamp) = count in last 300 sec
 */
public class basic_dsa_three_hundred_sixty_two {

    // Problem: hit(timestamp), getHits(timestamp) returns hits in (timestamp-300, timestamp].

    static class HitCounter {
        int[] times = new int[300];
        int[] hits = new int[300];

        public void hit(int timestamp) {
            int i = timestamp % 300;
            if (times[i] != timestamp) {
                times[i] = timestamp;
                hits[i] = 0;
            }
            hits[i]++;
        }

        public int getHits(int timestamp) {
            int sum = 0;
            for (int i = 0; i < 300; i++)
                if (timestamp - times[i] < 300)
                    sum += hits[i];
            return sum;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Design Hit Counter");
        System.out.println("=".repeat(60));

        HitCounter hc = new HitCounter();
        hc.hit(1);
        hc.hit(2);
        hc.hit(3);
        System.out.println("hit(1,2,3) getHits(4)=" + hc.getHits(4));
        hc.hit(300);
        System.out.println("hit(300) getHits(300)=" + hc.getHits(300));
        System.out.println("getHits(301)=" + hc.getHits(301));
    }
}
