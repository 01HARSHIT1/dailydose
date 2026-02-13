/**
 * Basic DSA Problems - Min Stack
 * Stack with O(1) getMin operation
 */
import java.util.Stack;

public class basic_dsa_two_hundred_ninety {

    // Problem: Support push, pop, top, getMin all O(1).
    // getMin returns minimum element in stack.

    static class MinStack {
        Stack<Integer> st = new Stack<>();
        Stack<Integer> minSt = new Stack<>();

        public void push(int val) {
            st.push(val);
            minSt.push(minSt.isEmpty() ? val : Math.min(minSt.peek(), val));
        }

        public void pop() {
            st.pop();
            minSt.pop();
        }

        public int top() {
            return st.peek();
        }

        public int getMin() {
            return minSt.peek();
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
