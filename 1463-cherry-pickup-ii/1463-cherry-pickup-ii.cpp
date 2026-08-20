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
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        //return rec(0,0,grid[0].size()-1,grid);
        return dpp(0,0,grid[0].size()-1,grid,dp);
    }
};