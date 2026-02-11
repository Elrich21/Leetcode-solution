# Search Insert Position

## 🧩 Problem Description

You are given a **sorted array** of distinct integers `nums` and a target value `target`.

Your task is to:

* Return the **index** if the target is found.
* If not found, return the **index where it would be inserted** to maintain sorted order.

The solution must run in **O(log n)** time.

---

## 📌 Example

### Example 1

```text
Input: nums = [1,3,5,6], target = 5
Output: 2
```

### Example 2

```text
Input: nums = [1,3,5,6], target = 2
Output: 1
```

### Example 3

```text
Input: nums = [1,3,5,6], target = 7
Output: 4
```

---

## 💡 Approach (Binary Search)

Since the array is already sorted, **binary search** is the optimal approach.

### Key Idea:

* Perform binary search on the array
* If the target is found, return its index
* If not found, the position where the loop ends (`low`) is the correct insert position

---

## ✅ Implementation (C++)

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // If target is not found, low is the insert position
        return low;
    }
};
```

---

## 🧠 Why Returning `low` Works

When the binary search ends:

* `low` points to the **first index where the target can be placed**
* This position maintains the sorted order

So:

* Found target → return index
* Not found → return `low`

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(log n)`
* **Space Complexity:** `O(1)`

---

## 🎯 Key Takeaway

> Binary search doesn’t just help you find elements —
> it also tells you **where elements belong**.

---

## 🚀 Status

✔ Solved
✔ Optimized
✔ Interview-ready
✔ Uses Binary Search
