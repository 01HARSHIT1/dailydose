/**
 * Basic DSA Problems - Design Phone Directory (LeetCode 379)
 * get(), check(), release() for numbers 0 to maxNumbers-1
 */
public class basic_dsa_three_hundred_seventy_nine {

    // Problem: maxNumbers. get() returns available or -1. check(n), release(n).

    static class PhoneDirectory {
        java.util.Queue<Integer> freed = new java.util.LinkedList<>();
        java.util.Set<Integer> freedSet = new java.util.HashSet<>();
        int next, max;

        PhoneDirectory(int maxNumbers) {
            max = maxNumbers;
        }

        public int get() {
            if (!freed.isEmpty()) {
                int n = freed.poll();
                freedSet.remove(n);
                return n;
            }
            if (next < max) return next++;
            return -1;
        }

        public boolean check(int number) {
            if (number < 0 || number >= max) return false;
            if (number >= next) return true;
            return freedSet.contains(number);
        }

        public void release(int number) {
            if (number >= 0 && number < max && number < next && !freedSet.contains(number)) {
                freedSet.add(number);
                freed.offer(number);
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Design Phone Directory");
        System.out.println("=".repeat(60));

        PhoneDirectory pd = new PhoneDirectory(3);
        System.out.println("get()=" + pd.get() + ", get()=" + pd.get() + ", check(2)=" + pd.check(2));
        pd.release(2);
        System.out.println("release(2), check(2)=" + pd.check(2) + ", get()=" + pd.get());
    }
}
