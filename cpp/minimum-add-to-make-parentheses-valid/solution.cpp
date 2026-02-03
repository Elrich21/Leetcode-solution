class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n = s.length();
        int count = 0;
        if(s.empty())
        {
            return 0;
        }

        std::stack<char> st;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == ')'){
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
                continue;

            }
            else{
            st.push(s[i]);
            }
            }


            else{
            st.push(s[i]);
            }
            
        }

        while(!st.empty())
        {
            count++;
            st.pop();
            
        }

        return count;
    }
};
