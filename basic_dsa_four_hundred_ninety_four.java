/**
 * Basic DSA Problems - One Fundamental Queue/Two-Pointer Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_ninety_four {
    
    // Problem 1: Implement Queue using Two Stacks
    // Implement a first-in-first-out (FIFO) queue using only two stacks.
    //
    // Operations:
    // - push(x): add to back
    // - pop(): remove from front
    // - peek(): get front
    // - empty(): whether queue is empty
    
    public static class MyQueue {
        private int[] in;
        private int[] out;
        private int inSize;
        private int outSize;
        
        public MyQueue() {
            in = new int[16];
            out = new int[16];
            inSize = 0;
            outSize = 0;
        }
        
        public void push(int x) {
            ensureInCapacity(inSize + 1);
            in[inSize++] = x;
        }
        
        public Integer pop() {
            moveIfNeeded();
            if (outSize == 0) return null;
            return out[--outSize];
        }
        
        public Integer peek() {
            moveIfNeeded();
            if (outSize == 0) return null;
            return out[outSize - 1];
        }
        
        public boolean empty() {
            return inSize == 0 && outSize == 0;
        }
        
        private void moveIfNeeded() {
            if (outSize != 0) return;
            while (inSize > 0) {
                ensureOutCapacity(outSize + 1);
                out[outSize++] = in[--inSize];
            }
        }
        
        private void ensureInCapacity(int needed) {
            if (needed <= in.length) return;
            int newCap = in.length * 2;
            while (newCap < needed) newCap *= 2;
            int[] ni = new int[newCap];
            System.arraycopy(in, 0, ni, 0, inSize);
            in = ni;
        }
        
        private void ensureOutCapacity(int needed) {
            if (needed <= out.length) return;
            int newCap = out.length * 2;
            while (newCap < needed) newCap *= 2;
            int[] no = new int[newCap];
            System.arraycopy(out, 0, no, 0, outSize);
            out = no;
        }
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Implement Queue using Two Stacks");
        System.out.println("=".repeat(60));
        
        MyQueue q = new MyQueue();
        System.out.println("empty: " + q.empty());
        System.out.println("peek: " + q.peek());
        System.out.println("pop : " + q.pop());
        
        System.out.println("\npush(1), push(2), push(3)");
        q.push(1);
        q.push(2);
        q.push(3);
        System.out.println("peek: " + q.peek()); // 1
        System.out.println("pop : " + q.pop());  // 1
        System.out.println("peek: " + q.peek()); // 2
        System.out.println("pop : " + q.pop());  // 2
        System.out.println("pop : " + q.pop());  // 3
        System.out.println("pop : " + q.pop());  // null
        System.out.println("empty: " + q.empty());
        
        System.out.println("\npush(10), push(20)");
        q.push(10);
        q.push(20);
        System.out.println("pop : " + q.pop());  // 10
        System.out.println("peek: " + q.peek()); // 20
        System.out.println("empty: " + q.empty());
    }
}

