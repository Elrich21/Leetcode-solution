🔢 4Sum — Find All Unique Quadruplets (C++)

This project implements an efficient solution to the 4Sum problem using sorting, nested loops, and the two-pointer technique.

The goal is to find all unique quadruplets in an array that sum up to a given target.

📌 Problem Statement

Given an array nums of n integers and an integer target, return all unique quadruplets
[nums[i], nums[j], nums[left], nums[right]] such that:

nums[i] + nums[j] + nums[left] + nums[right] == target


Constraints:

Each quadruplet must use four distinct indices

No duplicate quadruplets in the output

🧠 Approach & Intuition

The 4Sum problem is solved by reducing it step-by-step:

4Sum
 └── Fix first number (i)
      └── Fix second number (j)
           └── Solve 2Sum using two pointers

Steps:

Sort the array

Fix the first element (i)

Fix the second element (j)

Use two pointers (left, right) to find remaining two numbers

Skip duplicates at every level to avoid repeated quadruplets

⚙️ Implementation (C++)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[left] +
                        nums[right];

                    if (sum == target) {
                        res.push_back({
                            nums[i], nums[j], nums[left], nums[right]
                        });

                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

🔍 Why These Loop Boundaries?
Loop	Condition	Reason
i < n - 3	Leave space for 3 numbers	
j < n - 2	Leave space for 2 numbers	
left = j + 1	Avoid index reuse	
right = n - 1	Start from largest value	

Rule: Each loop must leave enough elements for the remaining numbers.

🛡️ Duplicate Handling

Duplicates are skipped at:

i level

j level

left pointer

right pointer

This guarantees unique quadruplets only.

⏱️ Time & Space Complexity
Metric	Complexity
Time	O(n³)
Space	O(1) (excluding output)

This is the optimal solution for 4Sum.

📚 Key Concepts Used

Sorting

Two-pointer technique

Nested loops

Duplicate elimination

Overflow-safe arithmetic (long long)

✅ Example

Input

nums = [-3, 0, 1, 2, 3, 3]
target = 3


Output

[[-3, 0, 3, 3], [-3, 1, 2, 3]]

🎯 Takeaway

4Sum is not an extension of 2Sum by counting

Always fix elements step-by-step

This pattern generalizes to kSum
