Binary Search Implementation in C++
📌 Problem Overview

This project implements Binary Search to find a target element in a sorted integer array.

Binary Search works by repeatedly dividing the search range in half, making it efficient with a time complexity of O(log n).

🧠 Approach

Initialize two pointers:

low → start of the array

high → end of the array

Calculate the middle index.

Compare the middle element with the target:

If equal → return the index

If target is greater → search the right half

If target is smaller → search the left half

Repeat until the element is found or the range is invalid.

💻 Code
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = n / 2;

        for (int i = 0; i < n; i++) {
            if (target == nums[mid]) {
                return mid;
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
            mid = (low + high) / 2;
        }
        return -1;
    }
};

⏱️ Complexity Analysis

Time Complexity: O(log n)

Space Complexity: O(1)

✅ Example

Input:

nums = [1, 3, 5, 7, 9]
target = 7


Output:

3

📚 Notes

The array must be sorted for binary search to work.

If the target element is not present, the function returns -1.
