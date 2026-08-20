// memoization

// class Solution {
// public:
//     int dpp(int m, int n, vector<vector<int>> &dp,
//             vector<vector<int>>& obstacleGrid) {

//         // Out of bounds
//         if (m < 0 || n < 0)
//             return 0;

//         // Obstacle
//         if (obstacleGrid[m][n] == 1)
//             return 0;

//         // Reached start
//         if (m == 0 && n == 0)
//             return 1;

//         // Already computed
//         if (dp[m][n] != -1)
//             return dp[m][n];

//         int up = dpp(m - 1, n, dp, obstacleGrid);
//         int left = dpp(m, n - 1, dp, obstacleGrid);

//         return dp[m][n] = up + left;
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         return dpp(m - 1, n - 1, dp, obstacleGrid);
//     }
// };


// tabulation

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         if(obstacleGrid[m-1][n-1]==1) // as itself a obstacle
//             return 0;

//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         dp[0][0]=1;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0){  // as otherwise i will overwrite dp[0][0]=1 to dp[0][0]=0;
//                     continue;
//                 }
//                 int up=0,left=0;
//                 if(i>0 && obstacleGrid[i-1][j]!=1)
//                     up=dp[i-1][j];
//                 if(j>0 && obstacleGrid[i][j-1]!=1)
//                     left=dp[i][j-1];
//                 dp[i][j]=up+left;
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };


//space optimised
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) // as itself a obstacle
            return 0;

        vector<int>prev(n,0);
        prev[0]=1;
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){  
                    curr[j]=1;
                    continue;
                }
                int up=0,left=0;
                if(i>0 && obstacleGrid[i-1][j]!=1)
                    up=prev[j];
                if(j>0 && obstacleGrid[i][j-1]!=1)
                    left=curr[j-1];
                curr[j]=up+left;
            }
            prev=curr;
        }
        return prev[n-1];
    }
};
