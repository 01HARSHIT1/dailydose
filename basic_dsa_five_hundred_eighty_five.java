/**
 * Basic DSA Problems - One Fundamental Hash Map Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_eighty_five {

    // Problem 1: Logger Rate Limiter
    // Design a logger that receives messages with timestamps and prints each message
    // at most once every 10 seconds. shouldPrintMessage(timestamp, message) returns true
    // if the message should be printed at that time.
    //
    // Example:
    // shouldPrintMessage(1,"foo") -> true
    // shouldPrintMessage(2,"bar") -> true
    // shouldPrintMessage(3,"foo") -> false
    // shouldPrintMessage(8,"bar") -> false
    // shouldPrintMessage(10,"foo") -> false
    // shouldPrintMessage(11,"foo") -> true

    static class Logger {
        private final java.util.HashMap<String, Integer> lastPrinted = new java.util.HashMap<>();

        /**
         * Track last print time per message
         * Time Complexity: O(1) per call
         * Space Complexity: O(u), u = unique messages
         */
        boolean shouldPrintMessage(int timestamp, String message) {
            if (message == null) {
                return false;
            }
            Integer last = lastPrinted.get(message);
            if (last != null && timestamp < last + 10) {
                return false;
            }
            lastPrinted.put(message, timestamp);
            return true;
        }
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Logger Rate Limiter");
        System.out.println("=".repeat(60));

        Logger log = new Logger();
        System.out.println("t=1 foo -> " + log.shouldPrintMessage(1, "foo"));
        System.out.println("t=2 bar -> " + log.shouldPrintMessage(2, "bar"));
        System.out.println("t=3 foo -> " + log.shouldPrintMessage(3, "foo"));
        System.out.println("t=8 bar -> " + log.shouldPrintMessage(8, "bar"));
        System.out.println("t=10 foo -> " + log.shouldPrintMessage(10, "foo"));
        System.out.println("t=11 foo -> " + log.shouldPrintMessage(11, "foo"));
        System.out.println("null msg -> " + log.shouldPrintMessage(1, null));
    }
}
