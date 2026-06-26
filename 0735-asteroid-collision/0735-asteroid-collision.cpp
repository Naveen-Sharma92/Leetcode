class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n= asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            long long a=asteroids[i];
            bool y= true;
            while(!st.empty() && (a<0) && (st.top() >0)){
                if(abs(a)<abs(st.top()))
                    a=st.top();
                else if(abs(a)==abs(st.top())){
                    y=false;
                    st.pop();
                    break;
                }
                st.pop();
            }
            if(y)
                st.push(a);
        }
        vector<int>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};