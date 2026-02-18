class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        vector<int> res(arr.size());
        

        for(int i = 0; i < arr.size()-1; i++)
        {
            int max= -1;
            for(int j = i+1; j < arr.size(); j++)
            {
                if(arr[j]>max)
                {
                    max = arr[j];
                }
            }

            
            
                res[i] = max;
            

           
        }

        res[arr.size()-1] = -1;

        return res;


        
    }
};
