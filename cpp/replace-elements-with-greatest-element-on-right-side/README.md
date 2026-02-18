# 🔄 Replace Elements with Greatest Element on Right Side — LeetCode Solution

## 📌 Problem Overview

Given an integer array `arr`, replace every element with the **greatest element among the elements to its right**, and replace the last element with `-1`.

The goal is to return the transformed array.

---

## 🧠 Approach

We create a result vector `res` of the same size as `arr`.
For every index `i`, we search for the maximum element present on the **right side** of that index.

### Key Idea

* Use a nested loop:

  * Outer loop selects the current index.
  * Inner loop finds the maximum value to the right.
* Store that maximum inside `res[i]`.
* The last element always becomes `-1`.

---

## ⚙️ Algorithm Steps

1. Create a result vector `res` with the same size as `arr`.
2. Traverse the array from index `0` to `n-2`.
3. For each index:

   * Initialize `max = -1`.
   * Check all elements to the right (`i+1` to end).
   * Update `max` whenever a larger value is found.
4. Assign `res[n-1] = -1`.
5. Return the result vector.

---

## 💻 Implementation (C++)

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        vector<int> res(arr.size());
        
        for(int i = 0; i < arr.size()-1; i++)
        {
            int max = -1;
            for(int j = i+1; j < arr.size(); j++)
            {
                if(arr[j] > max)
                {
                    max = arr[j];
                }
            }
            res[i] = max;
        }

        res[arr.size()-1] = -1;

        return res;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n²)`
  For each element, we scan all elements to the right.

* **Space Complexity:** `O(n)`
  A new result array is created.

---

## 📊 Example

Input:

```
arr = [17, 18, 5, 4, 6, 1]
```

Output:

```
[18, 6, 6, 6, 1, -1]
```

Explanation:

* Right max of 17 → 18
* Right max of 18 → 6
* Right max of 5 → 6
* Right max of 4 → 6
* Right max of 6 → 1
* Last element → -1

---

## 🚀 Key Learning

* Nested loops can be used to compute suffix-based properties.
* Always handle edge cases like the last index separately.
* This is a brute-force approach; it can be optimized to `O(n)` by traversing from right to left while maintaining a running maximum.

---

## ✨ Author

**Elrich** — Competitive Programming & DSA Practice
