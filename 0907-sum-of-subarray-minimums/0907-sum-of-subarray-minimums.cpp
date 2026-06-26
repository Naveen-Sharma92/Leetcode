class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        long long ans=0;
        vector<int>pse(n,-1);
        vector<int>nse(n,n);
        const int MOD= 1e9+7;
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i] )
                st.pop();
            if(!st.empty())
                pse[i]=st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }


        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i] ) // Rule to remember For monotonic stack problems with duplicates:PSE: >, NSE: >= or PSE: >=, NSE: >  /Maximums PGE: <, NGE: <= or PGE: <=, NGE: <
                st.pop();
            if(!st.empty())
                nse[i]=st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++){
            long long a= i-pse[i];
            long long b= nse[i]-i;
            ans = (ans + a * b % MOD * arr[i]) % MOD;
        }
        return (int)ans;
    }
};