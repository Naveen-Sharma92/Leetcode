class MedianFinder {
public:
    priority_queue<int> left; // max heap // s in vid 14 gfg heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap // gin gfg
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // initially both empty
        if(left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        // balance the heaps
        if(left.size() > right.size()+1){
            right.push(left.top());
            left.pop();
        }

        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size())
            return (left.top() + right.top()) / 2.0;

        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */