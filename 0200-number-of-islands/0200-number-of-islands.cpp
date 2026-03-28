class Solution {
public:
    void bfs(vector<vector<int>>& visited,vector<vector<char>>& grid,int x,int y){
        queue<pair<int,int>>q;
        q.push({x,y});
        visited[x][y]=1;
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            //neighbours
            // if 8 directions allowed
        //     for(int dr=-1;dr<=1;dr++){
        //         for(int dc=-1;dc<=1;dc++){
        //             if(row + dr>=0 && row + dr<grid.size() && col+dc>=0 && col+dc<grid[0].size()){
        //                 if(!visited[row+dr][col+dc] && grid[row+dr][col+dc] !='0'){
        //                     q.push({row+dr,col+dc});
        //                     visited[row+dr][col+dc]=1;
        //                 }
        //             }
        //         }
        //     }
        // }
        // for 4 directions
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            if(row + dr[k]>=0 && row + dr[k]<grid.size() && col+dc[k]>=0 && col+dc[k]<grid[0].size()){
                        if(!visited[row+dr[k]][col+dc[k]] && grid[row+dr[k]][col+dc[k]] !='0'){
                            q.push({row+dr[k],col+dc[k]});
                            visited[row+dr[k]][col+dc[k]]=1;
                        }
                    }
        }
        
    }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    bfs(visited,grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};