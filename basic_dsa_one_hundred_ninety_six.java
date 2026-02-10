/**
 * Basic DSA Problems - Min Stack
 * Stack that supports push, pop, top, and getMin in O(1)
 */
import java.util.ArrayDeque;
import java.util.Deque;

public class basic_dsa_one_hundred_ninety_six {

    // Problem: Implement stack with push, pop, top, getMin - all O(1).

    public static class MinStack {
        Deque<Integer> stack = new ArrayDeque<>();
        Deque<Integer> minStack = new ArrayDeque<>();

        public void push(int val) {
            stack.push(val);
            if (minStack.isEmpty() || val <= minStack.peek()) minStack.push(val);
        }

        public void pop() {
            int x = stack.pop();
            if (minStack.peek() != null && minStack.peek().equals(x)) minStack.pop();
        }

        public int top() {
            return stack.peek();
        }

        public int getMin() {
            return minStack.peek();
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Min Stack");
        System.out.println("=".repeat(60));

        MinStack ms = new MinStack();
        ms.push(-2);
        ms.push(0);
        ms.push(-3);
        System.out.println("getMin -> " + ms.getMin());
        ms.pop();
        System.out.println("top -> " + ms.top());
        System.out.println("getMin -> " + ms.getMin());
    }
}
