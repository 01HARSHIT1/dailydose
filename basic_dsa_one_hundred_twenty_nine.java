/**
 * Basic DSA Problems - Implement Stack using Queues
 * LIFO stack with push, pop, top, empty using only queue operations
 */
import java.util.*;

public class basic_dsa_one_hundred_twenty_nine {

    // Problem: Implement a LIFO stack using only one or two queues. push, pop, top, empty.

    static class MyStack {
        private final Queue<Integer> q = new ArrayDeque<>();

        public void push(int x) {
            int n = q.size();
            q.offer(x);
            for (int i = 0; i < n; i++) q.offer(q.poll());
        }

        public int pop() {
            return q.poll();
        }

        public int top() {
            return q.peek();
        }

        public boolean empty() {
            return q.isEmpty();
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Implement Stack using Queues");
        System.out.println("=".repeat(60));

        MyStack st = new MyStack();
        st.push(1);
        st.push(2);
        System.out.println("top -> " + st.top());
        System.out.println("pop -> " + st.pop());
        System.out.println("empty -> " + st.empty());
    }
}
