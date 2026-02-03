🧠 Min Add to Make Parentheses Valid

LeetCode: Min Add to Make Parentheses Valid
Topics: String · Stack · Greedy

📝 Problem

Given a string s consisting only of '(' and ')', return the minimum number of parentheses we must add to make the string valid.

A parentheses string is valid if:

Every opening bracket has a closing bracket

Brackets are properly nested

💡 Key Idea (Stack Pattern)

We simulate real bracket matching using a stack.

Rules
Current char	Stack top	Action
(	anything	push
)	(	pop (matched pair)
)	empty or )	push (unmatched)

After processing the whole string:

Stack contains only unmatched brackets
Each one needs one insertion to fix

So the answer is simply:

stack.size()

✅ Stack Solution C++

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n = s.length();
        int count = 0;
        if(s.empty())
        {
            return 0;
        }

        std::stack<char> st;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == ')'){
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
                continue;

            }
            else{
            st.push(s[i]);
            }
            }


            else{
            st.push(s[i]);
            }
            
        }

        while(!st.empty())
        {
            count++;
            st.pop();
            
        }

        return count;
    }
};

⚡ Greedy Solution (Optimal Space)

We don’t actually need a stack. We just count imbalance.

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, add = 0;

        for (char c : s) {
            if (c == '(') open++;
            else {
                if (open > 0) open--;
                else add++;
            }
        }

        return open + add;
    }
};

🧪 Example
Input:  "()))(("
Output: 4


Unmatched:

2 extra ')'

2 extra '('

Total insertions = 4

⏱️ Complexity
Approach	Time	Space
Stack	O(n)	O(n)
Greedy	O(n)	O(1)
