class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        if(n>1)
            dp[1]=nums[1];
        for(int i=2;i<n;i++){
            int maxi=0;
            for(int j=0;j<i-1;j++){
                maxi=max(dp[j]+nums[i],maxi);
            }
            dp[i]=maxi;

        }
        if(n<=1)
            return dp[0];
        return max(dp[n-1],dp[n-2]);
    }
};