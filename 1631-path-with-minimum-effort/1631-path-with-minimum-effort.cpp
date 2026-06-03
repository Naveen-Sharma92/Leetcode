class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
     // dist,row,col
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        dist[0][0]=0;
        q.push({0,{0,0}});

        while(!q.empty()){
            int d= q.top().first;
            int r= q.top().second.first;
            int c= q.top().second.second;
            q.pop();


            if(d>dist[r][c])
                continue;
                int dr[]={0,-1,0,+1};
                int dc[]={-1,0,1,0};
            for(int i=0;i<4;i++){

                    int rd= r+dr[i];
                    int cd = c+dc[i];
                    
                    if(rd>=0 && cd>=0 && rd<n && cd<m){
                        int nd= max(d,abs(heights[rd][cd]-heights[r][c]));
                        if(dist[rd][cd]> nd){
                            dist[rd][cd] =nd;
                            q.push({nd,{rd,cd}});
                        }
                    }
            }
        }
        if(dist[n-1][m-1]==1e9)
            return -1;
        else
            return dist[n-1][m-1];
    }
};