/**
 * Basic DSA Problems - Longest Absolute File Path (LeetCode 388)
 * Max length of path to file in "\n\t" formatted string
 */
public class basic_dsa_three_hundred_eighty_eight {

    // Problem: "\n"=newline, "\t"=depth. File has ".". Return max path length to file.

    /**
     * Split by "\n", count leading tabs for depth. Track prefix lens per depth.
     * Time O(n), Space O(d)
     */
    public static int lengthLongestPath(String input) {
        int max = 0;
        int[] lens = new int[input.length() + 1];
        for (String line : input.split("\n")) {
            int depth = 0;
            while (depth < line.length() && line.charAt(depth) == '\t') depth++;
            String name = line.substring(depth);
            int len = (depth > 0 ? lens[depth - 1] + 1 : 0) + name.length();
            lens[depth] = len;
            if (name.contains(".")) max = Math.max(max, len);
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Longest Absolute File Path");
        System.out.println("=".repeat(60));

        String s = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
        System.out.println("dir/subdir1/file1.ext style -> " + lengthLongestPath(s));
    }
}
