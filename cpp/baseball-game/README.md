Baseball Game Tracker
A C++ solution to keep track of scores in a specialized baseball game based on a series of record-keeping operations.

📝 Problem Description
You are given a list of strings operations, where each string is one of the following:

Integer x: Record a new score of x.
+: Record a new score that is the sum of the previous two scores.
D: Record a new score that is double the previous score.
C: Invalidate the previous score, removing it from the record.
The goal is to return the sum of all scores currently on the record.

🚀 The Solution
This implementation utilizes a Stack (std::stack) to manage the scores and a Vector (std::vector) to easily sum the final results.

Logic Breakdown:
Numbers: Converted using stoi() and pushed to both the stack and vector.
+: Peeks at the top two elements of the stack to calculate their sum.
D: Peeks at the top element and multiplies it by 2.
C: Removes the most recent element from both data structures.
Complexity Analysis
Time Complexity: $O(n)$, where $n$ is the number of operations. We iterate through the list once.
Space Complexity: $O(n)$ to store the scores in the stack and vector.
🛠️ Code Snippet
C++ 
class Solution {
public:
int calPoints(vector<string>& operations) {
vector<int> vec;
std::stack<int> st;

for(string& op : operations) {
if(op == "+") {
int top = st.top();
st.pop();
int new_score = top + st.top();
st.push(top); // Put the first one back
st.push(new_score);
vec.push_back(new_score);
}
else if(op == "C") {
vec.pop_back();
st.pop();
}
else if(op == "D") {
int doubled = st.top() * 2;
st.push(doubled);
vec.push_back(doubled);
}
else {
int val = stoi(op);
vec.push_back(val);
st.push(val);
}
}

int totalSum = 0;
for(int x : vec) totalSum += x;
return totalSum;
}
};

📋 How to Use
Include <vector>, <string>, and <stack> in your C++ environment.
Pass a vector<string> of operations to the calPoints function.
The function returns the final integer sum.
