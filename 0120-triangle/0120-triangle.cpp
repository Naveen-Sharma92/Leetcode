//memoisation

// class Solution {
// public:
//     int dpp(int m,int n, vector<vector<int>>& dp,vector<vector<int>>& triangle){
//         if(m<0 || n<0)
//             return INT_MAX;
//         if(m==0)
//             return triangle[0][0];
//         if (dp[m][n] != -1)
//             return dp[m][n];
//         int up= INT_MAX,upleft=INT_MAX;

//         if(n>0){
//             if(dp[m-1][n-1] !=-1)
//                 upleft = dp[m-1][n-1]+triangle[m][n];
//             else{
//                 dp[m-1][n-1] = dpp(m-1,n-1,dp,triangle);
//                 upleft = dp[m-1][n-1]+triangle[m][n];
//             }
//         }
//         if(m>n){
//             if(dp[m-1][n] !=-1)
//                 up = dp[m-1][n]+triangle[m][n];
//             else{
//                 dp[m-1][n] = dpp(m-1,n,dp,triangle);
//                 up = dp[m-1][n]+triangle[m][n];
//             }
//         }
//         return dp[m][n] = min(up,upleft);
        
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m= triangle.size();
//         int n= triangle[m-1].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         int ans= INT_MAX;
//         for( int i= 0;i<n;i++){
//             ans= min(ans,dpp(m-1,i,dp,triangle));
//         }
//         return ans;
//     }
// };

// tabulation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m= triangle.size();
        int n= triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans= INT_MAX;
        dp[0][0]= triangle[0][0];

        for(int i=0;i<m;i++){
            n= triangle[i].size();
            
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    continue;
                int upleft=INT_MAX,up=INT_MAX;
                if(j>0){
                    upleft = dp[i-1][j-1]+triangle[i][j];
                }
                if(i>j){
                    up = dp[i-1][j]+triangle[i][j];
                }
                dp[i][j]=min(up,upleft);
            }
        }

        for(int j=0;j<n;j++)
            ans= min(ans,dp[m-1][j]);
        return ans;
    }
};