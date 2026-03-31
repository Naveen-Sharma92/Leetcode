// exactly like surrounded regions problem
class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        while(!q.empty()){
            
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            int dr[]={-1,0,0,1};
            int dc[]={0,-1,1,0};
            for(int k=0;k<4;k++){
                int ur=a+dr[k];
                int uc=b+dc[k];
                if(ur >=0 && ur<m && uc>=0 && uc<n){
                    if(grid[ur][uc]==1 && visited[ur][uc]==0){
                        visited[ur][uc]=1;
                        q.push({ur,uc});
                    }

                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int c=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int j = 0; j < n; j++) {
            int i=0;
            if(!visited[i][j]  && grid[i][j]==1){
                    bfs(i,j,grid,visited);
            }

            i=m-1;
            if(!visited[i][j]  && grid[i][j]==1){
                    bfs(i,j,grid,visited);
            }
        }

        for(int i = 0; i < m; i++) {
            int j=0;
            if(!visited[i][j]  && grid[i][j]==1){
                    bfs(i,j,grid,visited);
            }

            j=n-1;
            if(!visited[i][j]  && grid[i][j]==1){
                    bfs(i,j,grid,visited);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && grid[i][j]==1)
                    c++;
            }
        }

        return c;
    }
};