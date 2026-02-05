🧱 MyStack — Stack Implementation Using vector in C++

This project demonstrates how to implement a Stack data structure in C++ using the vector container instead of the built-in std::stack.

The goal is to understand how stacks work internally and how STL containers like vector can be used to build custom data structures with O(1) operations.

🚀 Features

Push element to stack

Pop element from stack

View top element

Check if stack is empty

Safe handling for empty stack cases

All operations run in constant time – O(1)

📦 Implementation
class MyStack {
public:
    vector<int> vec;

    void push(int x) {
        vec.push_back(x);
    }
    
    int pop() {
        
        int val = vec.back();
        vec.pop_back();
        return val;
    }
    
    int top() {
        if (vec.empty()) throw runtime_error("Stack empty");
        return vec.back();
    }
    
    bool empty() {
        return vec.empty();
    }
};

🧠 How It Works

A stack follows LIFO (Last In, First Out).

vector is used because it provides:

Operation	Vector Method	Time Complexity
Push	push_back()	O(1)
Pop	pop_back()	O(1)
Top	back()	O(1)
Empty	empty()	O(1)

This is exactly how many standard library stacks are implemented internally.


▶️ Example Usage
MyStack st;

st.push(10);
st.push(20);

cout << st.top(); // 20

st.pop();

cout << st.top(); // 10

🎯 Why Not Use std::stack?

This project is for learning purposes — to understand:

How stacks are built internally

How STL containers can be used to implement data structures

Why std::stack works the way it does

⏱️ Time & Space Complexity
Operation	Complexity
Push	O(1)
Pop	O(1)
Top	O(1)
Empty	O(1)
Space	O(n)
📚 Concepts Covered

Stack (LIFO)

STL vector

Exception handling

Data structure design
