class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        unordered_map<char,int>m={{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};
        for(char c:s){
            if(m[c]>0)
                st.push(m[c]);
            else{
                if(st.empty())
                    return false;
                int k= st.top();
                st.pop();
                if(k+m[c]!=0)
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};