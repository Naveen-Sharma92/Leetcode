//recursion got tle
class Solution {
public:
int rec(int r,int c1,int c2,vector<vector<int>>& grid){
    int maxi=-1e8;
    if(r<0 || c1<0 || c2<0 || r>=grid.size() || c1>=grid[0].size() || c2>= grid[0].size()){
        return 0;
    }
    if(r== (grid.size()-1)){
        if(c1==c2)
            return grid[r][c1];
        else
            return grid[r][c1]+grid[r][c2];
    }
    else{
        for(int i=-1;i<2;i++){
            int value=0;
            for(int j=-1;j<2;j++){
                if(c1==c2){
                    value= grid[r][c1]+ rec(r+1,c1+i,c2+j,grid);
                }
                else{
                    value=grid[r][c1]+grid[r][c2]+ rec(r+1,c1+i,c2+j,grid);
                }
                maxi= max(value,maxi);
            }
            
        }

    }
    return maxi;
}
// memeoization
 int dpp(int r,int c1,int c2,vector<vector<int>>&grid,vector<vector<vector<int>>>& dp){
    int maxi=-1e8;
    if(r<0 || c1<0 || c2<0 || r>=grid.size() || c1>=grid[0].size() || c2>= grid[0].size()){
        return 0;
    }
    if(r== (grid.size()-1)){
        if(c1==c2)
            return grid[r][c1];
        else
            return grid[r][c1]+grid[r][c2];
    }
    if(dp[r][c1][c2]!=-1)
        return dp[r][c1][c2];


        for(int i=-1;i<2;i++){
            int value=0;
            for(int j=-1;j<2;j++){
                if(c1==c2){
                    value= grid[r][c1]+ dpp(r+1,c1+i,c2+j,grid,dp);
                }
                else{
                    value=grid[r][c1]+grid[r][c2]+ dpp(r+1,c1+i,c2+j,grid,dp);
                }
                maxi= max(value,maxi);
            }
            
        }

    return dp[r][c1][c2] = maxi;

 }
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int m=c,n=r;
        //vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1))); for memoization
        //return rec(0,0,grid[0].size()-1,grid); rec
        //return dpp(0,0,grid[0].size()-1,grid,dp); memoization

        // tabulation
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,0)));
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2)
                    dp[n-1][j1][j2] = grid[n-1][j1];
                else
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        for(int i = n-2; i >= 0; i--) { //ROW
            for(int j1 = 0; j1 < m; j1++) { //C1
                for(int j2 = 0; j2 < m; j2++) { //C2
                    int maxi = -1e8;

                    for(int dj1 = -1; dj1 <= +1; dj1++) {
                        for(int dj2 = -1; dj2 <= +1; dj2++) {
                            int value = 0;

                            if(j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m)
                                value += dp[i+1][j1+dj1][j2+dj2];
                            else
                                value+=(-1e8);

                            maxi = max(maxi, value);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];

    }
};