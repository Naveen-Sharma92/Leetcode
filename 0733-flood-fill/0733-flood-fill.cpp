class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int org=image[sr][sc];
        visited[sr][sc]=1;
        while(!q.empty()){
            int r=q.front().first;
            int c = q.front().second;
            image[r][c]=color;
            q.pop();
            int dr[]={-1,0,0,1};
            int dc[]={0,-1,1,0};
            for(int k=0;k<4;k++){
                int ur=r+dr[k];
                int uc=c+dc[k];
                if(ur>=0 && ur<m && uc>=0 && uc<n && image[ur][uc]==org && visited[ur][uc]==0){
                    visited[ur][uc]=1;
                    q.push({ur,uc});
                }
            }

        }
        return image;
    }
};