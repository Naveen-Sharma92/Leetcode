class MyStack {
public:
    queue<int> a, b;
    MyStack() {
    }
     
    void push(int x) {
        while(!a.empty()){
            int y= a.front();
            a.pop();
            b.push(y);
        }
        a.push(x);
        while(!b.empty()){
            int y= b.front();
            b.pop();
            a.push(y);
        }
    }
    
    int pop() {
        if(a.empty())
            return NULL;
        int y= a.front();
        a.pop();
        return y;
    }
    
    int top() {
        if(a.empty())
            return NULL;
        return a.front();
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */