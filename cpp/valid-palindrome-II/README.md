# Valid Palindrome II

## 🧩 Problem Statement
Given a string `s`, return `true` if the string can be a palindrome after deleting **at most one character**.  
Otherwise, return `false`.

---

## ✅ Approach: Two Pointers + Helper Check

A palindrome reads the same forwards and backwards.

### Key Idea:
- Use **two pointers** (`left`, `right`) to compare characters from both ends
- If characters match → move inward
- If they don’t match → try **skipping either the left or right character**
- Check if either resulting substring is a palindrome

Only **one deletion** is allowed.

---

## 💡 Algorithm
1. Initialize two pointers: `left = 0`, `right = s.length() - 1`
2. While `left < right`:
   - If `s[left] == s[right]`, move both pointers inward
   - Otherwise:
     - Check if substring `(left + 1, right)` is a palindrome  
     - OR if substring `(left, right - 1)` is a palindrome
3. If either check is true, return `true`
4. If the loop finishes without issues, return `true`

---

## 🔧 Helper Function
`isPalindrome(s, l, r)` checks whether a substring is a palindrome using two pointers.

---

## 🧪 Example

### Input:
s = "abca"

markdown
Copy code

### Explanation:
- Remove `'b'` → `"aca"` ✅ palindrome  
- OR remove `'c'` → `"aba"` ✅ palindrome

### Output:
true

csharp
Copy code

---

## 🧠 Code Implementation (C++)

```cpp
class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};
⏱️ Complexity Analysis
Time Complexity: O(n)

Space Complexity: O(1)

🎯 Key Takeaways
Only one mismatch can be tolerated

Two-pointer strategy keeps it efficient

Helper function avoids code duplication

Clean and interview-friendly solution

