class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        int fresh=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({{i,j},ans});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int c=q.front().second;
            ans=max(c,ans);
            q.pop();
            int dr[]={-1,0,0,1};
            int dc[]={0,-1,1,0};
            for(int k=0;k<4;k++){
                int ur=i+dr[k];
                int uc=j+dc[k];
                if(ur>=0 && ur<m && uc>=0 && uc<n && grid[ur][uc]==1){
                    q.push({{ur,uc},c+1});
                    fresh--;
                    grid[ur][uc]=2;
                }
            }
        }
        if(fresh>0)
            return -1;
        return ans;

        
        

    }
};