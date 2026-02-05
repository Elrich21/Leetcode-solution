class MyStack {
public:
 vector<int> vec;
    MyStack() {
        //creation of vector

       
        
    }
    
    void push(int x) {
        return vec.push_back(x);
        
    }
    
    int pop() {
        int val = vec.back();
        vec.pop_back();

        return val;
        
    }
    
    int top() {
        
        return vec.back();
        
    }
    
    bool empty() {
        if(vec.empty())
        {
            return true;
        }

        return false;
        
    }

};

