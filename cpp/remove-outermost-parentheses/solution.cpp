class Solution {
public:
    string removeOuterParentheses(string s) {
        std::stack<char> st;
        std::string res = "";


        for(char c : s)
        {
            if(c == '(')
            {
                if(!st.empty())
                {
                    res.push_back(c);
                }

                st.push(c);
            }

            else{
                st.pop();
                if(!st.empty())
                {
                    res.push_back(c);
                }
            }
        }

        return res;
    }
};
