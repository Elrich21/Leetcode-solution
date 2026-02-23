# 🔢 Find Max Consecutive Ones — Solution Explanation

## 📌 Problem

Given a binary array `nums` (containing only `0`s and `1`s), return the **maximum number of consecutive `1`s** present in the array.

---

## 🧠 Approach

The idea is simple:

* Traverse the array once.
* Maintain a `count` variable to track the current streak of `1`s.
* Maintain a `max` variable to store the highest streak found so far.
* If the current element is:

  * `1` → increase `count`
  * `0` → reset `count` to `0`
* After each step, update `max` if `count` becomes larger.

This ensures an **O(n)** time complexity with constant extra space.

---

## ⚙️ Code

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count = 0;
        int max = 0;

        for(int i = 0 ; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                count++;
            }
            else if(nums[i] == 0)
            {
                count = 0;
            }

            if(count > max)
            {
                max = count;
            }
        }

        return max;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
  We traverse the array only once.

* **Space Complexity:** `O(1)`
  No extra data structures are used.

---

## 💡 Key Concepts

* Sliding count technique
* Single pass traversal
* Tracking maximum value dynamically

---

## ✅ Example

**Input**

```
nums = [1,1,0,1,1,1]
```

**Output**

```
3
```

**Explanation:**
The longest consecutive sequence of `1`s is `[1,1,1]`.

---

## 🚀 Notes

* Avoid naming variables `max` in real-world projects because it can conflict with the standard library function `std::max`.
* A better name could be `maxCount`.

---
