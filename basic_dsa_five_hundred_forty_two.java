/**
 * Basic DSA Problems - One Fundamental Stack Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_forty_two {

    // Problem 1: Min Stack
    // Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    //
    // Implement:
    // - push(x): pushes element x onto stack
    // - pop(): removes element on top
    // - top(): gets top element
    // - getMin(): retrieves minimum element

    static class MinStack {
        private final java.util.Stack<Integer> data = new java.util.Stack<>();
        private final java.util.Stack<Integer> mins = new java.util.Stack<>();

        public void push(int val) {
            data.push(val);
            if (mins.isEmpty() || val <= mins.peek()) {
                mins.push(val);
            } else {
                mins.push(mins.peek());
            }
        }

        public Integer pop() {
            if (data.isEmpty()) {
                return null;
            }
            mins.pop();
            return data.pop();
        }

        public Integer top() {
            if (data.isEmpty()) {
                return null;
            }
            return data.peek();
        }

        public Integer getMin() {
            if (mins.isEmpty()) {
                return null;
            }
            return mins.peek();
        }
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Min Stack");
        System.out.println("=".repeat(60));

        MinStack st = new MinStack();
        st.push(-2);
        st.push(0);
        st.push(-3);
        System.out.println("getMin -> " + st.getMin()); // -3
        System.out.println("pop -> " + st.pop());       // -3
        System.out.println("top -> " + st.top());       // 0
        System.out.println("getMin -> " + st.getMin()); // -2
        System.out.println("pop -> " + st.pop());       // 0
        System.out.println("pop -> " + st.pop());       // -2
        System.out.println("top (empty) -> " + st.top());
        System.out.println("getMin (empty) -> " + st.getMin());
    }
}
