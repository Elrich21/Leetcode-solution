🧮 Evaluate Reverse Polish Notation (RPN) – C++ Solution

This project contains a C++ implementation to evaluate an arithmetic expression written in Reverse Polish Notation (Postfix Notation) using a stack.

📌 Problem Statement

Reverse Polish Notation is a mathematical notation where every operator follows all of its operands.

For example:

["2","1","+","3","*"]  =>  (2 + 1) * 3 = 9
["4","13","5","/","+"] =>  4 + (13 / 5) = 6


The task is to evaluate the expression and return the final integer result.

🧠 Key Concept

The solution uses a stack to process numbers and operators.

Rule:

When an operator is encountered:

Pop the second operand from the stack.

Pop the first operand from the stack.

Apply the operator: first op second.

Push the result back to the stack.

This order is very important for - and /.

⚙️ Algorithm

For each token in the input:

If the token is a number → push it to the stack.

If the token is an operator:

Pop two numbers from the stack.

Perform the operation.

Push the result back.

At the end, the stack contains the final result.

💻 C++ Implementation

#include<cctype>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> num;
        int res = 0;

        for(int i = 0; i < tokens.size(); i ++)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
    
    num.push(std::stoi(tokens[i]));
} 

            else
            {
                if(tokens[i] == "+"){
                    int temp = num.top();
                    num.pop();
                    res = temp + num.top();
                    num.pop();
                    num.push(res);
                }
                else if(tokens[i] == "-"){
                    int temp = num.top();
                    num.pop();
                    res = num.top() - temp;
                    num.pop();
                    num.push(res);
                }
                else if(tokens[i] == "*"){
                    int temp = num.top();
                    num.pop();
                    res = temp * num.top();
                    num.pop();
                    num.push(res);
                }
                else if(tokens[i] == "/"){
                    int temp =num.top();
                    num.pop();
                    res =  num.top() / temp;
                    num.pop();
                    num.push(res);
                }
            }

        }
res = num.top();
        return res;
    }
};

🧪 Example Walkthrough

Input:

["2","1","+","3","*"]


Stack operations:

Push 2
Push 1
+  => 2 + 1 = 3
Push 3
*  => 3 * 3 = 9


Output: 9

⏱️ Complexity Analysis
Metric	Value
Time Complexity	O(n)
Space Complexity	O(n)

Where n is the number of tokens.

🧩 Concepts Used

Stack Data Structure

String to Integer Conversion (stoi)

Conditional operator handling

Reverse Polish Notation evaluation logic

🎯 Learning Outcome

This problem strengthens understanding of:

Stack-based expression evaluation

Operand order importance in postfix expressions

Writing clean, reusable stack patterns for expression problems
