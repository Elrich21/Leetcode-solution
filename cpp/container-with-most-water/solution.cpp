class Solution {
public:
    int maxArea(vector<int>& height) {
        int cc = 0,cc2 = 0;//to compare the current in-loop max with the universal max
        int right = height.size()-1;//right pointer
        int left =0 ;//left pointer
         int n = height.size();//size of the vec

        
        int j = 0;//iteration inside loop

        while(j<n-1)//1 less cause the 0th element will be left
        {
          if(height[right] < height[left]) // if right most heigth is less
          {
            cc2 = height[right] * (right-left); //the min height * the number of spaces between the them
            if(cc2 > cc) //if in-loop capacity is greater then change the uni max
            {
                cc = cc2;
                //std::cout<<cc2<<" "<<cc;
                
            }
            right--;//since right was min decrement and find if grater then the last one
                
          }

          else //(height[left] < height[right]) or (height[left] == height[right])
          {
            cc2 = height[left] * (right-left);//sam as earlier
            if(cc2 > cc)
            {
                cc = cc2;
                //std::cout<<cc2<<" "<<cc;
                
            }
            
                left++;//inc left if case lower then right
          }
          j++;//increment j
        }

        return cc; // retunr final max capacity
        //chose cc -> cubic capaicty (mm) ;)
    }
};
