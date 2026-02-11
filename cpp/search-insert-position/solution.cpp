class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int low = 0;
        int high = n;
        int mid  = 0;
        int i = 0;
        int j = 0;

        


        while(low<=high)
        {
            mid = low + (high - low) / 2;


            if(target == nums[mid])
            {
                return mid;
            }

            else if(target > nums[mid])
            {
                low = mid+1;
                
            }


            else if(target < nums[mid])
            {
                high = mid-1;
                j++;
            }
            
        }

        cout << j << i;

        return low;




        
        
    }
};
