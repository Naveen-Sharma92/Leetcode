//wrong greedy

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount==0)
//             return 0;
//         int ans=0;
//         sort(coins.begin(),coins.end());
//         int n= coins.size();
//         while(amount>=coins[0]){
//             for(int i=n-1;i>=0;i--){
//                 if(amount>=coins[i]){
//                     amount-=coins[i];
//                     ans++;
//                     break;
//                 }
//             }
            
//         }
//         if(ans==0 || amount>0)
//             return -1;
//         return ans;
        
//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans=0;
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=amount;i++){
            for(auto it:coins){
                //if(dp[i]!=INT_MAX && i+it<=amount){ -> this gives runtime error
                if(it <= amount-i && dp[i] != INT_MAX){
                    dp[i+it]=min(dp[i+it],dp[i]+1);
                }
            }
        }
        if(dp[amount]!=INT_MAX)
            return dp[amount];

        return -1;
        
    }
};