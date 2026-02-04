class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> vec;
        int n = operations.size();

        std::stack<int> st;


        for(int i= 0; i < n; i++)
        {
            

             if(operations[i] == "+")
            {
                int previdx = 0;
                int sum1 = 0;
                previdx = st.top();
                st.pop();
                sum1 = previdx+st.top();
                st.push(previdx);
                vec.push_back(sum1);
                st.push(sum1);

            }

            else if(operations[i] == "C")
            {
                vec.pop_back();
                st.pop();
            }

            else if(operations[i] == "D")
            {
                int temp = 0;
                temp = st.top();
                temp = temp*2;

                st.push(temp);
                vec.push_back(temp);
            }
            else
            {
                vec.push_back(stoi(operations[i]));
                st.push(stoi(operations[i]));
            }
        }
        int sum = 0;

        for(int x: vec)
        {
            sum +=x;

        }

        return sum;    }
};
