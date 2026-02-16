🔁 Concatenation of Array — LeetCode Solution
📌 Problem Overview

Given an integer array nums, the task is to create a new array ans such that:

ans = nums + nums

This means the original array is concatenated with itself, preserving the same order of elements.

🧠 Approach

We create an empty vector ans and push all elements of nums into it twice using nested loops.

Key Idea

Outer loop runs 2 times → represents duplicating the array.

Inner loop iterates through all elements of nums.

Each element is added to ans using push_back().

⚙️ Algorithm Steps

Create an empty vector ans.

Run a loop from 0 to 1 (two iterations).

Inside it, traverse the nums array.

Push each element into ans.

Return ans.

💻 Implementation (C++)
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        vector<int> ans;

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                ans.push_back(nums[j]);
            }
        }

        return ans;
    }
};
⏱️ Complexity Analysis

Time Complexity: O(n)
We traverse the array twice, which is linear.

Space Complexity: O(2n)
A new array of size 2 * n is created.

📊 Example

Input:

nums = [1, 2, 3]

Output:

[1, 2, 3, 1, 2, 3]
🚀 Key Learning

Array concatenation can be achieved using simple loops.

vector.push_back() dynamically grows the container.

Nested loops can still be linear when one loop runs a fixed number of times.

✨ Author

Elrich — DSA & Competitive Coding Practice
