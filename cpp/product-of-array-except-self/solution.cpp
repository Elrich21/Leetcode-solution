class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);


        //left of i

        for(int i = 1; i < n; i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
            //when i = 1, res[0] * nums[0] = 1 * 1 = 1 = res[1]
            //if i = 2, then res[1] * nums[1] =  1 * 2 = 2 res[2]
            // now i = 3, then res[2] * nums[2] = 2 * 3 = 6 = res[3]
            //we get thw lwft , ignoring the ith pos

        }

        //cal left of ith products



        //right of ith element
        //so update res[i]
        int right = 1;//var to store the product to the right of element

        for(int i = n-1; i >= 0; i--) //descendong order
        {
            res[i] = res[i] * right;   //so the end element wont have right it will mul with garbage or zero value
            //right is tracker
            right = right*nums[i]; //update right with the cuurent pos of nums for n-1 element
        }

        return res;
    }
};
