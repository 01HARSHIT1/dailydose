/**
 * Basic DSA Problems - Implement Queue using Stacks
 * Queue (FIFO) with enqueue and dequeue using only stack operations
 */
import java.util.*;

public class basic_dsa_one_hundred_twenty_eight {

    // Problem: Implement a FIFO queue using only two stacks. push (enqueue), pop (dequeue), peek, empty.

    static class MyQueue {
        private final Deque<Integer> in = new ArrayDeque<>();
        private final Deque<Integer> out = new ArrayDeque<>();

        public void push(int x) {
            in.push(x);
        }

        public int pop() {
            peek();
            return out.pop();
        }

        public int peek() {
            if (out.isEmpty())
                while (!in.isEmpty()) out.push(in.pop());
            return out.peek();
        }

        public boolean empty() {
            return in.isEmpty() && out.isEmpty();
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Implement Queue using Stacks");
        System.out.println("=".repeat(60));

        MyQueue q = new MyQueue();
        q.push(1);
        q.push(2);
        System.out.println("peek -> " + q.peek());
        System.out.println("pop -> " + q.pop());
        System.out.println("empty -> " + q.empty());
    }
}
