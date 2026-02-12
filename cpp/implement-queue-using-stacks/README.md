MyQueue — Queue Implementation using Two Stacks (C++)
📌 Overview

MyQueue is a C++ implementation of a FIFO Queue using two std::stack<int> containers.
This approach is commonly used in Data Structures & Algorithms interviews to demonstrate how stack behavior can simulate queue operations.

The class supports the following operations:

push(x) → Insert element at the back of the queue

pop() → Remove and return the front element

peek() → View the front element without removing it

empty() → Check whether the queue is empty

⚙️ How It Works

The implementation uses two stacks:

st1 (Input Stack)

Used when pushing new elements.

st2 (Output Stack)

Used for popping and peeking elements.

🔄 Transfer Logic

Elements are moved from st1 to st2 only when st2 is empty.
This reverses the order once, allowing FIFO behavior.

push → st1
pop/peek → st2

This ensures efficient performance.

🚀 Time Complexity
Operation	Complexity
push	O(1)
pop	Amortized O(1)
peek	Amortized O(1)
empty	O(1)

Elements are transferred between stacks only when necessary, making operations efficient overall.

🧠 Key Idea

Stacks are LIFO, but a Queue is FIFO.

By using:

one stack for incoming elements

one stack for outgoing elements

we reverse order exactly once when needed.

📂 Class Implementation
class MyQueue {
    std::stack<int> st1;
    std::stack<int> st2;
public:
    MyQueue() {}

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int temp = st2.top();
        st2.pop();
        return temp;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};
🧪 Example Usage
MyQueue* obj = new MyQueue();
obj->push(1);
obj->push(2);
int front = obj->peek(); // 1
int removed = obj->pop(); // 1
bool isEmpty = obj->empty(); // false
🎯 Use Cases

Data Structures practice

Interview preparation

Understanding stack vs queue behavior

Amortized analysis concepts

✅ Summary

This implementation efficiently simulates a queue using two stacks by transferring elements only when required.
It achieves near O(1) performance for core operations and follows standard interview-level optimization.
