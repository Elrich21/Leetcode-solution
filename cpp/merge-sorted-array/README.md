# Merge Sorted Array

## 🧩 Problem Description

You are given two integer arrays `nums1` and `nums2`, both sorted in non-decreasing order, and two integers `m` and `n`:

- `m` → number of valid elements in `nums1`
- `n` → number of elements in `nums2`

The array `nums1` has a total size of `m + n`, where:
- the first `m` elements are valid
- the last `n` elements are **placeholders (0)**

Your task is to merge `nums2` into `nums1` so that `nums1` becomes a single sorted array.  
The merge must be done **in-place**, without returning anything.

---

## 📝 Important Note

> The `0`s in `nums1` are **not data values**.  
> They are only placeholders to provide extra space.

Only the values defined by `m` and `n` should be considered valid.

---

## 📌 Example

### Example 1
```text
Input:
nums1 = [10,20,20,40,0,0], m = 4
nums2 = [1,2], n = 2

Output:
[1,2,10,20,20,40]
Example 2
text
Copy code
Input:
nums1 = [0,0], m = 0
nums2 = [1,2], n = 2

Output:
[1,2]
💡 Approach (In-Place, Optimal)
To avoid overwriting elements in nums1, we merge from the back.

Pointers Used:
i → last valid element of nums1 (m - 1)

j → last element of nums2 (n - 1)

k → last index of nums1 (m + n - 1)

Key Idea:
Compare elements from the end

Place the larger element at position k

Move pointers accordingly

If nums2 still has elements left, copy them

✅ Implementation (C++)
cpp
Copy code
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
❓ Why Only Copy Remaining nums2?
If nums1 has remaining elements, they are already in the correct position

If nums2 has remaining elements, they must be copied into nums1

Hence, only nums2 needs an extra loop

⏱️ Complexity Analysis
Time Complexity: O(m + n)

Space Complexity: O(1) (in-place)

🎯 Key Takeaway
Validity of elements is defined by m and n, not by the value 0.
