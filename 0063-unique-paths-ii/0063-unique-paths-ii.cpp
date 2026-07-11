class Solution {
public:
    int dpp(int m, int n, vector<vector<int>> &dp,
            vector<vector<int>>& obstacleGrid) {

        // Out of bounds
        if (m < 0 || n < 0)
            return 0;

        // Obstacle
        if (obstacleGrid[m][n] == 1)
            return 0;

        // Reached start
        if (m == 0 && n == 0)
            return 1;

        // Already computed
        if (dp[m][n] != -1)
            return dp[m][n];

        int up = dpp(m - 1, n, dp, obstacleGrid);
        int left = dpp(m, n - 1, dp, obstacleGrid);

        return dp[m][n] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dpp(m - 1, n - 1, dp, obstacleGrid);
    }
};