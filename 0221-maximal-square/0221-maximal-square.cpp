class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m= matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0')
                    continue;
                else{
                    int upleft=0,up=0,left=0;
                    if(j-1>=0 && i-1>=0)
                        upleft=dp[i-1][j-1];
                    if(j-1>=0)
                        left=dp[i][j-1];
                    if(i-1>=0)
                        up=dp[i-1][j];
                    dp[i][j]=min(upleft,min(up,left))+1;
                    maxi=max(maxi,dp[i][j]);
            }
            }
        }
        return maxi*maxi;  //as maxi is side length
    }
};