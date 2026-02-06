class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res; //result
        int n  = nums.size();

        //edge case if only few elements are present
        if(n<4)
        {
            return res;
        }

        //sorting-ascending order
        sort(nums.begin(),nums.end());
        //-3,0,1,2,3,3

        for(int i = 0; i < n - 3; i++)//first element of vector
        {
            if(i > 0 && nums[i] == nums[i-1]) continue; // skiping duplicates

            for(int j = i+1; j < n - 2; j++)//second element of vector
            {
                if(j>i+1 && nums[j] == nums[j-1]) continue;

                int left = j + 1; //third element of vector
                int right = n -1;//last element of vector

                while(left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum == target)
                    {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});

                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                    }
                    else if(sum<target)
                    {
                        left++;
                    }

                    else right--;
                   
                }
            }
        }
return res;

    }
};
