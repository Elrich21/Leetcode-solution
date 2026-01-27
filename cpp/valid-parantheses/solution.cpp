class Solution {
public:
    bool isValid(string s) {

        std::stack<char> st;//stack

        for(int i = 0; i < s.size();i++)
        {
            if(s[i]=='{' || s[i]=='(' || s[i]=='[' )
            {
                st.push(s[i]);//accept openening paraenthesis and push into the stack
            }

            else // when condition is } , ) , ]
            {
                if(st.empty()) return false; //if stack is empty return false;

                int top = st.top();//keeps tarck of the top element
                st.pop();//removes the latest element in case it pairs correctley or fails to match as given i the below condition

                if ((s[i] == ')' && top != '(') || (s[i] == '}' && top != '{') || (s[i] == ']' && top != '[')) {//this is to check if the closing paranthesis does not matches top element then it fails  
                    return false;

            }
        }



        }


            return st.empty(); //return if stack is empty or not (True/False)

             
    }
       
    
};
