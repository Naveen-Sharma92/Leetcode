class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val>mini)
                st.push(val);
            else{
                st.push((1LL*2*val-mini));
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        long long val =st.top();
        if(val>mini)
            st.pop();
        else{
            mini = 1LL*2*mini-val;
            st.pop();
        }
    }
    
    int top() {
        long long val= st.top();
        if(val>mini)
            return val;
        else
            return mini;
    }
    
    int getMin() {
        return mini;
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