class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         int n = temperatures.size();
        std::stack<int> st;
         vector<int> res(n, 0);//set all the elements in the vec to 0
       

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])//to check if it is greater               //compared to st.top() as it holds the previous max value
            {
                int previdx = st.top();  //gets the previous max index
                st.pop();//pop from stack
                res[previdx] = i - previdx;//
            }
            st.push(i);//at i =0 inex 0 is pushed directly
        }

        return res;
    }
};

