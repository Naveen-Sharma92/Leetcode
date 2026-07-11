//memeoisation

class Solution {
public:
    int dpp(int m,int n,vector<vector<int>> &dp,vector<vector<int>>& grid){
        if(m==0 && n==0)
            return grid[0][0];
        
        int up=INT_MAX,left=INT_MAX;
        if(m-1>=0){
            if(dp[m-1][n] != -1)
                up = grid[m][n] + dp[m-1][n];
            else{
                dp[m-1][n]= dpp(m-1,n,dp,grid);
                up=grid[m][n] + dp[m-1][n];
            }
        }
        if(n-1>=0){
            if(dp[m][n-1] != -1)
                left = grid[m][n] + dp[m][n-1];
             else{
                dp[m][n-1]= dpp(m,n-1,dp,grid);
                left=grid[m][n] + dp[m][n-1];
            }
        }

        return dp[m][n] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return dpp(m-1,n-1,dp,grid);
    }
};