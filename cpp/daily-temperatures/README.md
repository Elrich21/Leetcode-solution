# 🌡️ Daily Temperatures — Monotonic Stack (C++)

## 🧠 Problem

Given an array `temperatures` where `temperatures[i]` represents the temperature on day `i`, return an array `answer` such that:

> `answer[i]` is the number of days you have to wait after day `i` to get a warmer temperature.
> If no future day has a warmer temperature, keep it as `0`.

---

## 💡 Key Insight

This problem is a classic **Next Greater Element to the Right** pattern.

To solve it efficiently in **O(n)** time, we use a **Monotonic Decreasing Stack** that stores **indices** of days whose warmer temperature hasn't been found yet.

---

## 🚀 Approach (Monotonic Stack)

* Traverse the array from left to right.
* Maintain a stack that stores indices of unresolved days.
* For each day `i`:

  * While the current temperature is higher than the temperature at the index on the top of the stack:

    * Pop the index from the stack.
    * Calculate how many days it took to find a warmer temperature.
  * Push the current index onto the stack.

This ensures each index is pushed and popped at most once → **O(n)**.

---

## 🧾 Code (C++)

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIdx = st.top();
                st.pop();
                res[prevIdx] = i - prevIdx;
            }
            st.push(i);
        }

        return res;
    }
};
```

---

## ⏱️ Complexity

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n)  |
| Space      | O(n)  |

---

## 🧩 Pattern Recognition

This same pattern is used in:

* Next Greater Element
* Stock Span Problem
* Largest Rectangle in Histogram

Whenever you see:
**"Next greater / warmer / larger element to the right" → Think Monotonic Stack**

---

## 🧪 Example

Input:

```
[73,74,75,71,69,72,76,73]
```

Output:

```
[1,1,4,2,1,1,0,0]
```

---

## 🏁 Conclusion

Using a monotonic stack reduces a brute-force O(n²) approach to an optimal O(n) solution and is a must-know technique for coding interviews.
