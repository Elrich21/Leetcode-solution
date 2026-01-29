class MinStack {
public:
    MinStack() {
       
    }
     std::stack<int> st;
       // std::cout<<"Stack created";
        std::stack<int> minStack;
        //std::cout<<"Min stack created";
    void push(int val) {
        st.push(val);
        if(minStack.empty() || minStack.top() > val)
        {
            minStack.push(val);
        }
        else {
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        if(!minStack.empty())
        {
            minStack.pop();
            st.pop();
        }
    }
    
    int top() {
        if(!minStack.empty())
        {
            //return minStack.top();
            return st.top();
        }
        else
        {
            return NULL;
        }
    }
    
    int getMin() {
         if(minStack.empty())
        {
            return NULL;
           
        }
        else{
            return minStack.top();
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
