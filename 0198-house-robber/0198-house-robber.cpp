
// my approch time complexity o(N square) space complexity= o(1)

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n= nums.size();
//         vector<int>dp(n+1,0);
//         dp[0]=nums[0];
//         if(n>1)
//             dp[1]=nums[1];
//         for(int i=2;i<n;i++){
//             int maxi=0;
//             for(int j=0;j<i-1;j++){
//                 maxi=max(dp[j]+nums[i],maxi);
//             }
//             dp[i]=maxi;

//         }
//         if(n<=1)
//             return dp[0];
//         return max(dp[n-1],dp[n-2]);
//     }
// };


class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        if(n>1)
            dp[1]=max(nums[1],nums[0]);
        int maxi=0;
        for(int i=2;i<n;i++){
           maxi = max(dp[i-1],dp[i-2]+nums[i]);
           dp[i]= maxi;

        }
        if(n<=1)
            return dp[0];
        return max(dp[n-1],dp[n-2]);
    }
};
