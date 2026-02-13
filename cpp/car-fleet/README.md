🚗 853. Car Fleet

Topics: Array · Stack · Greedy · Sorting

📝 Problem Summary

You are given:

A target mile

Arrays position[i] and speed[i] for n cars

Each car drives toward the target.

Rules

Cars cannot overtake

A faster car behind can catch up to a slower car ahead

Once cars meet, they move together at the slower speed

That group is called a car fleet

👉 Return how many fleets reach the target.

💡 Core Insight (Very Important)

You are not simulating cars.

You are comparing arrival times.

For each car:

𝑡
𝑖
𝑚
𝑒
=
𝑡
𝑎
𝑟
𝑔
𝑒
𝑡
−
𝑝
𝑜
𝑠
𝑖
𝑡
𝑖
𝑜
𝑛
𝑠
𝑝
𝑒
𝑒
𝑑
time=
speed
target−position
	​


But there is a catch…

Only cars behind can catch cars ahead

So we must preserve road order.

❗ Why we sort by position (not time)

Sorting by time destroys who is ahead/behind

Sorting by position keeps physical reality intact

Position tells who can catch whom
Time tells whether they will catch

🧠 Algorithm Idea

Compute (position, time_to_target) for every car

Sort cars by position descending (closest to target first)

Traverse from front to back

Maintain lastFleetTime

If current car’s time is greater → new fleet

Else → joins existing fleet

✅ C++ Implementation
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        // Step 1: Build (position, time) pairs
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Step 2: Sort by position descending
        sort(cars.begin(), cars.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Step 3: Count fleets
        int fleets = 0;
        double lastFleetTime = 0;

        for (auto &car : cars) {
            double currTime = car.second;

            if (currTime > lastFleetTime) {
                fleets++;
                lastFleetTime = currTime;
            }
        }

        return fleets;
    }
};

🧪 Example

Input

target = 12
position = [10,8,0,5,3]
speed    = [2,4,1,1,3]


Computed Times

Position	Time
10	1
8	1
5	7
3	3
0	12

Fleet Formation

(10,8) → Fleet

(5,3) → Fleet

(0) → Fleet

Output: 3

⏱️ Complexity
Step	Complexity
Build pairs	O(n)
Sort	O(n log n)
Traverse	O(n)

Total: O(n log n) time, O(n) space
