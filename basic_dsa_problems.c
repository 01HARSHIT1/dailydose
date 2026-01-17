#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

/**
 * Basic DSA Interview Problems
 * Collection of fundamental DSA problems covering stacks, queues, trees,
 * binary search, two pointers, and sliding window techniques
 */

#define MAX_SIZE 10000

// ==================== STACK STRUCTURE ====================
typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(capacity * sizeof(int));
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int val) {
    if (stack->top < stack->capacity - 1) {
        stack->data[++stack->top] = val;
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return -1;
}

int peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return -1;
}

void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

// ==================== QUEUE STRUCTURE ====================
typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return queue->rear < queue->front;
}

void enqueue(Queue* queue, int val) {
    if (queue->rear < queue->capacity - 1) {
        queue->data[++queue->rear] = val;
    }
}

int dequeue(Queue* queue) {
    if (!isQueueEmpty(queue)) {
        return queue->data[queue->front++];
    }
    return -1;
}

void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

// ==================== TREE NODE STRUCTURE ====================
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ==================== STACK PROBLEMS ====================

// Problem 1: Valid Parentheses
bool validParentheses(char* s) {
    Stack* stack = createStack(strlen(s));
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(stack, s[i]);
        } else {
            if (isEmpty(stack)) {
                freeStack(stack);
                return false;
            }
            char top = peek(stack);
            if ((s[i] == ')' && top != '(') ||
                (s[i] == '}' && top != '{') ||
                (s[i] == ']' && top != '[')) {
                freeStack(stack);
                return false;
            }
            pop(stack);
        }
    }
    
    bool result = isEmpty(stack);
    freeStack(stack);
    return result;
}

// Problem 3: Daily Temperatures
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    Stack* stack = createStack(temperaturesSize);
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    
    for (int i = 0; i < temperaturesSize; i++) {
        while (!isEmpty(stack) && temperatures[peek(stack)] < temperatures[i]) {
            int idx = pop(stack);
            result[idx] = i - idx;
        }
        push(stack, i);
    }
    
    freeStack(stack);
    return result;
}

// ==================== BINARY SEARCH PROBLEMS ====================

// Problem 6: Binary Search
int binarySearch(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

// Problem 8: Search Insert Position
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
}

// ==================== TWO POINTER PROBLEMS ====================

// Problem 9: Two Sum (Sorted Array)
int* twoSumSorted(int* numbers, int numbersSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int left = 0, right = numbersSize - 1;
    
    while (left < right) {
        int currentSum = numbers[left] + numbers[right];
        if (currentSum == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    *returnSize = 0;
    free(result);
    return NULL;
}

// Problem 10: Remove Duplicates from Sorted Array
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    
    int writeIndex = 1;
    
    for (int readIndex = 1; readIndex < numsSize; readIndex++) {
        if (nums[readIndex] != nums[readIndex - 1]) {
            nums[writeIndex] = nums[readIndex];
            writeIndex++;
        }
    }
    
    return writeIndex;
}

// Problem 11: Valid Palindrome
bool isPalindrome(char* s) {
    int left = 0, right = strlen(s) - 1;
    
    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

// Problem 12: Container With Most Water
int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maxWater = 0;
    
    while (left < right) {
        int width = right - left;
        int currentArea = (height[left] < height[right] ? height[left] : height[right]) * width;
        maxWater = (currentArea > maxWater) ? currentArea : maxWater;
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxWater;
}

// ==================== SLIDING WINDOW PROBLEMS ====================

// Problem 13: Maximum Average Subarray
double findMaxAverage(int* nums, int numsSize, int k) {
    double currentSum = 0;
    for (int i = 0; i < k; i++) {
        currentSum += nums[i];
    }
    double maxSum = currentSum;
    
    for (int i = k; i < numsSize; i++) {
        currentSum = currentSum - nums[i - k] + nums[i];
        maxSum = (currentSum > maxSum) ? currentSum : maxSum;
    }
    
    return maxSum / k;
}

// Problem 15: Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(char* s) {
    int charIndex[128];
    memset(charIndex, -1, sizeof(charIndex));
    
    int maxLength = 0;
    int start = 0;
    int len = strlen(s);
    
    for (int end = 0; end < len; end++) {
        if (charIndex[s[end]] >= start) {
            start = charIndex[s[end]] + 1;
        }
        
        charIndex[s[end]] = end;
        int currentLength = end - start + 1;
        maxLength = (currentLength > maxLength) ? currentLength : maxLength;
    }
    
    return maxLength;
}

// ==================== HASH TABLE PROBLEMS ====================

// Problem 16: Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    *returnSize = 0;
    free(result);
    return NULL;
}

// Problem 17: Contains Duplicate
bool containsDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

// ==================== TREE PROBLEMS ====================

// Problem 19: Maximum Depth of Binary Tree
int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

// Problem 20: Same Tree
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    
    if (p == NULL || q == NULL) {
        return false;
    }
    
    return (p->val == q->val && 
            isSameTree(p->left, q->left) && 
            isSameTree(p->right, q->right));
}

// Problem 21: Invert Binary Tree
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

// Problem 22: Symmetric Tree
bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true;
    }
    if (left == NULL || right == NULL) {
        return false;
    }
    return (left->val == right->val && 
            isMirror(left->left, right->right) && 
            isMirror(left->right, right->left));
}

bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}

// Helper function to print array
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Test cases
int main() {
    printf("Problem 1 - Valid Parentheses:\n");
    printf("%s\n", validParentheses("()[]{}") ? "true" : "false");
    
    printf("\nProblem 6 - Binary Search:\n");
    int nums[] = {1, 2, 3, 4, 5};
    printf("%d\n", binarySearch(nums, 5, 3)); // 2
    
    printf("\nProblem 8 - Search Insert Position:\n");
    int nums2[] = {1, 3, 5, 6};
    printf("%d\n", searchInsert(nums2, 4, 5)); // 2
    
    printf("\nProblem 9 - Two Sum (Sorted):\n");
    int numbers[] = {2, 7, 11, 15};
    int returnSize;
    int* result = twoSumSorted(numbers, 4, 9, &returnSize);
    if (result) {
        printArray(result, returnSize);
        free(result);
    }
    
    printf("\nProblem 12 - Container With Most Water:\n");
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d\n", maxArea(height, 9)); // 49
    
    printf("\nProblem 16 - Two Sum:\n");
    int nums3[] = {2, 7, 11, 15};
    int* result2 = twoSum(nums3, 4, 9, &returnSize);
    if (result2) {
        printArray(result2, returnSize);
        free(result2);
    }
    
    printf("\nProblem 17 - Contains Duplicate:\n");
    int nums4[] = {1, 2, 3, 1};
    printf("%s\n", containsDuplicate(nums4, 4) ? "true" : "false");
    
    printf("\nProblem 19 - Maximum Depth of Binary Tree:\n");
    TreeNode* root = createTreeNode(3);
    root->left = createTreeNode(9);
    root->right = createTreeNode(20);
    root->right->left = createTreeNode(15);
    root->right->right = createTreeNode(7);
    printf("%d\n", maxDepth(root)); // 3
    
    return 0;
}
