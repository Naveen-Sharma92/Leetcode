
// tabulation
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,0));
//         for(int i=0;i<m;i++)
//             dp[i][0]=1;
//         for(int j=0;j<n;j++)
//             dp[0][j]=1;
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

// recursion got tle
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         if(m==1 || n==1) // as i am taking m and n insytead of m-1 and n-1
//             return 1;
//         return  uniquePaths(m,n-1)+uniquePaths(m-1,n);
//     }
// };


// memoization
class Solution {
public:
    int dpp(int m,int n,vector<vector<int>> &dp){
        if(m==0 || n==0)
            return 1;
        if(dp[m-1][n] == 0)
            dp[m-1][n]= dpp(m-1,n,dp);
        if(dp[m][n-1] ==0)
            dp[m][n-1] =dpp(m,n-1,dp);
        
        return dp[m][n-1] + dp[m-1][n];
    } 
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        return dpp(m-1,n-1,dp);
    }
};