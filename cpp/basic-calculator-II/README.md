🧮 Basic Calculator II — Stack Based Approach (C++)
This project implements a solution for the classic Basic Calculator II problem using a stack-based technique in C++.

The calculator evaluates a mathematical expression string containing:

Non-negative integers

Operators: +, -, *, /

Whitespace

The solution correctly handles operator precedence without using multiple stacks or converting the expression to postfix form.

🚀 Problem Statement

Given a string s representing a valid mathematical expression, evaluate it and return the result.

Example
Input:  "3+2*2"
Output: 7

Input:  " 3/2 "
Output: 1

Input:  " 3+5 / 2 "
Output: 5

💡 Key Insight (Core Logic)

Instead of using two stacks for numbers and operators, this solution uses:

✅ One stack + previous operator tracking

The Rule That Makes It Work
Operator	Action
+	Push number to stack
-	Push negative number to stack
*	Pop last number, multiply, push result
/	Pop last number, divide, push result

At the end, sum all elements in the stack.

This automatically respects operator precedence:

* and / are evaluated immediately

+ and - are resolved at the end

🧠 Why This Works

For expression: "3+2*2"

Step	Stack State
Push 3	[3]
Push 2	[3,2]
* 2 → 2×2 = 4	[3,4]
Sum	7

No operator stack required.

🛠️ Implementation (C++)
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';   // previous operator

        for(int i = 0; i < s.size(); i++) {

            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {

                if(op == '+') {
                    st.push(num);
                }
                else if(op == '-') {
                    st.push(-num);
                }
                else if(op == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * num);
                }
                else if(op == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / num);
                }

                op = s[i];
                num = 0;
            }
        }

        int result = 0;
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

📌 Features of This Approach

Handles multi-digit numbers

Ignores whitespace

Correct operator precedence

Uses only one stack

Time Efficient and Clean Logic

⏱️ Time & Space Complexity
Complexity	Value
Time	O(n)
Space	O(n) (stack)
🎯 Learning Outcome

This problem teaches an important pattern:

Immediate evaluation for high-precedence operators, delayed evaluation for low-precedence ones

This pattern is useful in many stack and expression parsing problems.

🧪 Test Cases to Try
"14-3/2"       → 13
"100+20*3"     → 160
"42"           → 42
"1+2*5/3+6/4*2"→ 6

📚 Concepts Used

Stack Data Structure

String Parsing

Operator Precedence Handling

Character to Integer Conversion

✅ Conclusion

This solution demonstrates a clean and efficient way to evaluate arithmetic expressions using stacks while keeping the logic simple and readable.
