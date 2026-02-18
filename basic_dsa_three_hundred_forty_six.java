/**
 * Basic DSA Problems - Moving Average from Data Stream (LeetCode 346)
 * Calculate moving average over sliding window of size
 */
public class basic_dsa_three_hundred_forty_six {

    // Problem: Window size. next(val) adds val, returns avg of last size values.

    static class MovingAverage {
        final int size;
        final java.util.Queue<Integer> q = new java.util.LinkedList<>();
        int sum = 0;

        MovingAverage(int size) { this.size = size; }

        public double next(int val) {
            q.offer(val);
            sum += val;
            if (q.size() > size) sum -= q.poll();
            return (double) sum / q.size();
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Moving Average from Data Stream");
        System.out.println("=".repeat(60));

        MovingAverage ma = new MovingAverage(3);
        System.out.println("next(1)=" + ma.next(1) + ", next(10)=" + ma.next(10)
                + ", next(3)=" + ma.next(3) + ", next(5)=" + ma.next(5));
    }
}
