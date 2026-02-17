class Solution {
public:
    int scoreOfString(string s) {
        

        
        int sum = 0;
        
        for(int i = 0; i < s.length()-1; i++)
        {

            sum+= abs(s[i] - s[i+1]);
            /*
           if(s[i] > s[i+1])
           {
            s[i] = s[i] - s[i+1];
            sum += s[i];
           }

           else if(s[i] < s[i+1])
           {
            s[i] = s[i+1] - s[i];
            sum+= s[i];
           }
           
             cout<<" ascii "<< s[i]<<"  :"<< sum<< "  ";
             //sum +=s[i];*/
        }

       

        return sum;

    }
};


