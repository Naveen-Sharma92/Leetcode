class Solution {
public:
    string removeKdigits(string num, int k) {
        int n= num.size();
        int K=k;
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && K>0 && st.top()>num[i]){
                st.pop();
                K--;
            }
            st.push(num[i]);
        }
        while(K>0 && !st.empty()){
            st.pop();
            K--;
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        //removing triling zeros
        int j=0;
        for(j=0;j<ans.size();j++){
            if(ans[j]=='0')
                continue;
            else
                break;
        }
        ans=ans.substr(j);
        if(ans.size()<=0)
            return "0";
        return ans;
    }
};