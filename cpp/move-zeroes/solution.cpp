class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> tmp;
        for (int num : nums) {
            if (num != 0) {
                tmp.push_back(num);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i < tmp.size()) {
                nums[i] = tmp[i];
            } else {
                nums[i] = 0;
            }
        }
    }
};
