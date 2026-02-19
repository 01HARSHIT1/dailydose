/**
 * Basic DSA Problems - Logger Rate Limiter (LeetCode 359)
 * ShouldPrintMessage: true if message not printed in last 10 seconds
 */
public class basic_dsa_three_hundred_fifty_nine {

    // Problem: shouldPrintMessage(timestamp, message) - true if not printed in last 10 sec.

    static class Logger {
        java.util.Map<String, Integer> last = new java.util.HashMap<>();

        public boolean shouldPrintMessage(int timestamp, String message) {
            int prev = last.getOrDefault(message, -10);
            if (timestamp - prev >= 10) {
                last.put(message, timestamp);
                return true;
            }
            return false;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Logger Rate Limiter");
        System.out.println("=".repeat(60));

        Logger log = new Logger();
        System.out.println("print(1,foo)=" + log.shouldPrintMessage(1, "foo")
                + " print(2,bar)=" + log.shouldPrintMessage(2, "bar")
                + " print(3,foo)=" + log.shouldPrintMessage(3, "foo")
                + " print(8,bar)=" + log.shouldPrintMessage(8, "bar")
                + " print(10,foo)=" + log.shouldPrintMessage(10, "foo"));
    }
}
