# 🔎 Is Subsequence — LeetCode Solution

## 📌 Problem Overview

Given two strings `s` and `t`, determine whether `s` is a **subsequence** of `t`.

A subsequence is formed by deleting some (or no) characters from another string without changing the order of the remaining characters.

---

## 🧠 Approach

We use a **single pointer technique** to track how many characters of string `s` have been matched while iterating through string `t`.

### Key Idea

* Traverse string `t` character by character.
* Maintain a counter `count` that represents the current index in `s`.
* Whenever characters match, move the pointer forward.
* If all characters of `s` are matched, return `true`.

---

## ⚙️ Algorithm Steps

1. Store the length of string `s` in variable `n`.
2. Initialize a counter `count = 0`.
3. Loop through each character in `t`:

   * If the character matches `s[count]`, increment `count`.
   * If `count == n`, stop early since the subsequence is found.
4. After the loop:

   * If `count == n`, return `true`.
   * Otherwise return `false`.

---

## 💻 Implementation (C++)

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // size of string s
        int n = s.length();
        int count = 0;

        for(char x: t)
        {
            if(x == s[count])
            {
                count++;
            }

            if(count == n)
            {
                break;
            }
        }
        
        if(count == n)
        {
            return true;
        }

        return false;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(|t|)`
  We traverse string `t` once.

* **Space Complexity:** `O(1)`
  No extra data structures are used.

---

## 📊 Example

Input:

```
s = "abc"
t = "ahbgdc"
```

Process:

* Match `a`
* Match `b`
* Match `c`

Output:

```
true
```

---

## 🚀 Key Learning

* Subsequence problems often use a **two-pointer** or **single-pointer** traversal.
* Early termination (`break`) improves efficiency.
* Maintaining order is more important than matching positions.

---

## ✨ Author

**Elrich** — Competitive Programming & DSA Practice
