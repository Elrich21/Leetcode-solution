//solving using two pointers method
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res; //to store the result array
        int n = nums.size(); // size of the vector

        //sorting the array
        sort(nums.begin(),nums.end());

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0) break; //if first element is greater then zero no subtraction operation would be possible

            if(i > 0 && nums[i] == nums[i-1]) continue; // skips duplicate

            int right = n -1; //roght pointer
            int left = i + 1; // left pointer

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right]; //sum

                if(sum < 0) left++;// if less reduce negtivity
                else if(sum > 0)right--; // if more increase positivity
                else{
                    //when sum is 0 -> required condition
                    res.push_back({nums[i],nums[left],nums[right]}); // add to the result vector

                    while(left < right && nums[left] == nums[left+1])left++; // avoids duplicate
                    while(left < right && nums[right] == nums[right - 1]) right--; // avoids dupliacte for right pointer

                    left++; // move to next element
                    right--;
                }
            }
        }

        return res;










    }
};