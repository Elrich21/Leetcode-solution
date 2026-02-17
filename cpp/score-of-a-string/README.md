🔢 Score of a String — LeetCode Solution
📌 Problem Overview

The goal is to calculate the score of a string by summing the absolute differences between the ASCII values of every pair of adjacent characters.

For a string s, the score is defined as:

[
\sum |s[i] - s[i+1]|
]

where the difference is taken using ASCII values.

🧠 Approach

Instead of manually comparing characters using multiple conditions, we can directly compute the absolute difference using the abs() function.

Key Idea

Characters in C++ behave like integers (ASCII values).

Loop through the string until the second last character.

Add the absolute difference between adjacent characters to a running total.

⚙️ Algorithm Steps

Initialize a variable sum to store the total score.

Traverse the string from index 0 to length - 2.

At each step:

Compute abs(s[i] - s[i+1]).

Add it to sum.

Return sum.

💻 Implementation (C++)
class Solution {
public:
    int scoreOfString(string s) {
        
        int sum = 0;
        
        for(int i = 0; i < s.length()-1; i++)
        {
            sum += abs(s[i] - s[i+1]);
        }

        return sum;
    }
};
⏱️ Complexity Analysis

Time Complexity: O(n)
We traverse the string once.

Space Complexity: O(1)
No extra data structures are used.

📊 Example

Input:

s = "code"

ASCII Values:

c = 99
o = 111
d = 100
e = 101

Calculation:

|99-111| = 12
|111-100| = 11
|100-101| = 1
Total Score = 24
🚀 Key Learning

Characters can be directly used in arithmetic operations.

abs(a - b) simplifies logic when calculating differences.

Avoid modifying the original string when only calculation is required.

✨ Author

Elrich — Competitive Programming & DSA Practice
