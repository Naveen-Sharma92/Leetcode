//memeoisation

// class Solution {
// public:
//     int dpp(int m,int n,vector<vector<int>> &dp,vector<vector<int>>& grid){
//         if(m==0 && n==0)
//             return grid[0][0];
        
//         int up=INT_MAX,left=INT_MAX;
//         if(m-1>=0){
//             if(dp[m-1][n] != -1)
//                 up = grid[m][n] + dp[m-1][n];
//             else{
//                 dp[m-1][n]= dpp(m-1,n,dp,grid);
//                 up=grid[m][n] + dp[m-1][n];
//             }
//         }
//         if(n-1>=0){
//             if(dp[m][n-1] != -1)
//                 left = grid[m][n] + dp[m][n-1];
//              else{
//                 dp[m][n-1]= dpp(m,n-1,dp,grid);
//                 left=grid[m][n] + dp[m][n-1];
//             }
//         }

//         return dp[m][n] = min(up,left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m= grid.size();
//         int n= grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));

//         return dpp(m-1,n-1,dp,grid);
//     }
// };

//tabulation

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m= grid.size();
//         int n= grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         dp[0][0]=grid[0][0];

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 int down=INT_MAX,right=INT_MAX;
//                 if(i>0)
//                     down= grid[i][j] + dp[i-1][j];
//                 if(j>0)
//                     right=grid[i][j] + dp[i][j-1];
//                 if(i == 0 && j == 0)
//                     continue;
//                 dp[i][j]= min(down,right);
//             }

//         }
//         return dp[m-1][n-1];
//     }
// };

// state optimisation 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<int>prevrow(n,-1);

        for(int i=0;i<m;i++){
            vector<int>curr(n,-1);
            for(int j=0;j<n;j++){
                int down=INT_MAX,right=INT_MAX;
                if(i>0)
                    down= grid[i][j] + prevrow[j];
                if(j>0)
                    right=grid[i][j] + curr[j-1];
                if(i == 0 && j == 0)
                    curr[i]= grid[0][0];
                else
                    curr[j]= min(down,right);
            }
            prevrow=curr;

        }
        return prevrow[n-1];
    }
};