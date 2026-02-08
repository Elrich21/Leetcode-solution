class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mid = n/2;
        int low = 0;
        int high = n;

       

        for(int i = 0; i < n; i++){
             
        if(target == nums[mid])
        {
            return mid;
        }

        else if (target > nums[mid])
        {
            low = mid+1;
        }

        else if(target < nums[mid])
        {
            high = mid-1;
        }

        
        mid = (low+high)/2;

        }

       return -1;
    }
};
