class MyQueue {
public:
    stack<int>a,b;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!a.empty()){
            int y= a.top();
            a.pop();
            b.push(y);
        }
        a.push(x);
        while(!b.empty()){
            int y= b.top();
            b.pop();
            a.push(y);
        }
    }
    
    int pop() {
        int y= a.top();
        a.pop();
        return y;
    }
    
    int peek() {
        return a.top();
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */