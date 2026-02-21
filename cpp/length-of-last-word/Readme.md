# 📌 58. Length of Last Word — LeetCode Solution

## 🧩 Problem Statement
Given a string `s` consisting of words and spaces, return the **length of the last word** in the string.

A **word** is defined as a maximal substring consisting of non-space characters only.

---

## 💡 Approach

### ✅ Key Idea
Instead of splitting the string, we traverse it **from the end**:

1. Start from the last index.
2. Skip all trailing spaces.
3. Count characters until we reach a space or the beginning.
4. The count represents the length of the last word.

👉 This approach is optimal because:
- No extra space is used.
- Only one pass through the string.

---

## ⚙️ Algorithm Steps

- Initialize a pointer at the end of the string.
- Move left while encountering spaces.
- Start counting characters of the last word.
- Stop when a space or index `< 0` is found.

---

## 🚀 C++ Implementation

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.length() - 1;
        int len = 0;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count characters of last word
        while (i >= 0 && s[i] != ' ') {
            len++;
  
    return len;
    }
};
