# 🔄 Reverse String — C++ Solution

## 📌 Problem Overview
Given a character array `s`, reverse the string **in-place** without using extra memory.

This solution swaps characters from the beginning and end of the vector until the middle is reached.

---

## 🧠 Approach
We use a **two-pointer technique**:

- Start one pointer at the beginning (`i`)
- The second position is calculated as `n - 1 - i`
- Swap both characters
- Continue until half of the array is processed

Since each swap fixes two positions, we only need to loop until `n/2`.

---

## ⚙️ Algorithm Steps
1. Get the size of the vector `n`.
2. Loop from `i = 0` to `n/2`.
3. Swap:
   - `s[i]`
   - `s[n - 1 - i]`

---

## 💻 Implementation
```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        for (int i = 0; i < n / 2; i++) {
            char temp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = temp; // swapping elements
        }
    }
};
⏱️ Complexity Analysis
Time Complexity: O(n)

Space Complexity: O(1) (in-place reversal)

✅ Example
Input

css
Copy code
['h','e','l','l','o']
Output

css
Copy code
['o','l','l','e','h']
🎯 Key Concepts Used
Two Pointer Technique

In-place Swapping

Vector Manipulation in C++

🚀 Notes
No extra array is created.

Efficient and optimal for interviews and competitive programming.
