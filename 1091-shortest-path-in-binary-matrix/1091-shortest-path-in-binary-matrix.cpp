class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return -1;

        int n=grid.size();
        
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>>q; // dist,row,col
        dist[0][0]=0;
        q.push({0,{0,0}});

        while(!q.empty()){
            int d= q.front().first;
            int r= q.front().second.first;
            int c= q.front().second.second;
            q.pop();
            if(d>dist[r][c])
                continue;
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    if(dr==0 && dc==0)
                        continue;

                    int rd= r+dr;
                    int cd = c+dc;
                    
                    if(rd>=0 && cd>=0 && rd<n && cd<n && grid[rd][cd]==0){
                        if(dist[rd][cd]>d+1){
                            dist[rd][cd] =d+1;
                            q.push({d+1,{rd,cd}});
                        }
                    }
                }
            }
        }
        if(dist[n-1][n-1]==1e9)
            return -1;
        else
            return dist[n-1][n-1]+1;
    }
};