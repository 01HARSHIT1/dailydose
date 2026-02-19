/**
 * Basic DSA Problems - Design Snake Game (LeetCode 353)
 * Snake moves on grid, eats food to grow, dies on border or self bite
 */
public class basic_dsa_three_hundred_fifty_three {

    // Problem: width x height, food list. move(direction) returns score or -1 if dead.

    static class SnakeGame {
        int w, h, idx, score;
        int[][] food;
        java.util.Deque<int[]> snake = new java.util.ArrayDeque<>();
        java.util.Set<String> body = new java.util.HashSet<>();

        SnakeGame(int width, int height, int[][] food) {
            w = width;
            h = height;
            this.food = food;
            snake.offer(new int[]{0, 0});
            body.add("0,0");
        }

        public int move(String direction) {
            int[] head = snake.peekFirst();
            int r = head[0], c = head[1];
            switch (direction) {
                case "U": r--; break;
                case "D": r++; break;
                case "L": c--; break;
                case "R": c++; break;
            }
            if (r < 0 || r >= h || c < 0 || c >= w) return -1;
            boolean eating = idx < food.length && r == food[idx][0] && c == food[idx][1];
            if (!eating) {
                int[] tail = snake.pollLast();
                body.remove(tail[0] + "," + tail[1]);
            } else { idx++; score++; }
            if (body.contains(r + "," + c)) return -1;
            snake.offerFirst(new int[]{r, c});
            body.add(r + "," + c);
            return score;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Design Snake Game");
        System.out.println("=".repeat(60));

        SnakeGame g = new SnakeGame(3, 2, new int[][]{{1, 2}, {0, 1}});
        System.out.println("move(R)=" + g.move("R") + " move(D)=" + g.move("D") + " move(R)=" + g.move("R"));
    }
}
