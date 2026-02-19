/**
 * Basic DSA Problems - Data Stream as Disjoint Intervals (LeetCode 352)
 * Add numbers and return merged disjoint intervals
 */
public class basic_dsa_three_hundred_fifty_two {

    // Problem: addNum(val), getIntervals() returns sorted disjoint intervals.

    static class SummaryRanges {
        java.util.TreeMap<Integer, int[]> map = new java.util.TreeMap<>();

        public void addNum(int value) {
            Integer start = map.floorKey(value);
            if (start != null && map.get(start)[1] >= value) return;  // already in interval
            Integer lo = map.lowerKey(value), hi = map.higherKey(value);
            if (lo != null && map.get(lo)[1] + 1 == value && (hi == null || value + 1 != hi)) {
                map.get(lo)[1] = value;
            } else if (hi != null && value + 1 == hi && (lo == null || map.get(lo)[1] + 1 != value)) {
                map.put(value, new int[]{value, map.get(hi)[1]});
                map.remove(hi);
            } else if (lo != null && map.get(lo)[1] + 1 == value && hi != null && value + 1 == hi) {
                map.get(lo)[1] = map.get(hi)[1];
                map.remove(hi);
            } else if ((lo == null || map.get(lo)[1] + 1 < value) && (hi == null || value + 1 < hi)) {
                map.put(value, new int[]{value, value});
            }
        }

        public int[][] getIntervals() {
            return map.values().toArray(new int[0][]);
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Data Stream as Disjoint Intervals");
        System.out.println("=".repeat(60));

        SummaryRanges sr = new SummaryRanges();
        sr.addNum(1);
        System.out.println("addNum(1) -> " + java.util.Arrays.deepToString(sr.getIntervals()));
        sr.addNum(3);
        System.out.println("addNum(3) -> " + java.util.Arrays.deepToString(sr.getIntervals()));
        sr.addNum(7);
        System.out.println("addNum(7) -> " + java.util.Arrays.deepToString(sr.getIntervals()));
        sr.addNum(2);
        System.out.println("addNum(2) -> " + java.util.Arrays.deepToString(sr.getIntervals()));
    }
}
