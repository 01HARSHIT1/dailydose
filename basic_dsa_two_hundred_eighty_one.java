/**
 * Basic DSA Problems - Implement Stack using Queues
 * LIFO stack using only FIFO queues
 */
import java.util.LinkedList;
import java.util.Queue;

public class basic_dsa_two_hundred_eighty_one {

    // Problem: Implement stack (push, pop, top, empty) using only queues.

    static class MyStack {
        Queue<Integer> q = new LinkedList<>();

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
        System.out.println("push 1, push 2, top -> " + st.top());
        System.out.println("pop -> " + st.pop());
        System.out.println("empty -> " + st.empty());
    }
}
