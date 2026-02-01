#include<cctype>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> num;
        int res = 0;

        for(int i = 0; i < tokens.size(); i ++)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
    
    num.push(std::stoi(tokens[i]));
} 

            else
            {
                if(tokens[i] == "+"){
                    int temp = num.top();
                    num.pop();
                    res = temp + num.top();
                    num.pop();
                    num.push(res);
                }
                else if(tokens[i] == "-"){
                    int temp = num.top();
                    num.pop();
                    res = num.top() - temp;
                    num.pop();
                    num.push(res);
                }
                else if(tokens[i] == "*"){
                    int temp = num.top();
                    num.pop();
                    res = temp * num.top();
                    num.pop();
                    num.push(res);
                }
                else if(tokens[i] == "/"){
                    int temp =num.top();
                    num.pop();
                    res =  num.top() / temp;
                    num.pop();
                    num.push(res);
                }
            }

        }
res = num.top();
        return res;
    }
};
