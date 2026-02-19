class Solution {
public:
    bool isSubsequence(string s, string t) {
        //size of string s

        int n = s.length();
        int count = 0;

        for(char x: t)
        {
            if(x == s[count])
            {
                count++;
            }

            if(count == n)
            {
                break;
            }

        }
        

        if(count == n)
            {
                return true;
            }

            return false;
    }
};
