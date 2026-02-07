# Merge Strings Alternately (C++)

## 🧩 Problem Statement
Given two strings `word1` and `word2`, merge them by adding characters in alternating order, starting with `word1`.

If one string is longer than the other, append the remaining characters of the longer string at the end.

---

## 💡 Approach

- Use two pointers:
  - `left` for `word1`
  - `right` for `word2`
- Loop `n + m` times (total length of both strings).
- On each iteration:
  - Add one character from `word1` if available.
  - Add one character from `word2` if available.
- This ensures alternating characters and safely handles different string lengths.

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int o = n + m;
        string s;

        int left = 0;
        int right = 0;

        for(int i = 0; i < o; i++) {
            if (left < n) s += word1[left++];
            if (right < m) s += word2[right++];
        }
        return s;
    }
};
🧪 Example
Input

ini
Copy code
word1 = "abc"
word2 = "pqrs"
Output

arduino
Copy code
"apbqcrs"
⏱️ Complexity Analysis
Time Complexity: O(n + m)

Space Complexity: O(n + m) (for the result string)

🏁 Notes
No extra data structures are used.

Works efficiently even when strings have different lengths.

Simple pointer-based logic makes the solution easy to understand and maintain.
