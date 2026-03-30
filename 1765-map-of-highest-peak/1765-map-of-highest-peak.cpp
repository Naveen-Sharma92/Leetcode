class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            int dr[]={-1,0,0,1};
            int dc[]={0,-1,1,0};
            for(int k=0;k<4;k++){
                int ur=i+dr[k];
                int uc=j+dc[k];
                if(ur>=0 && ur<m && uc>=0 && uc<n && ans[ur][uc]==-1){
                    q.push({ur,uc});
                    ans[ur][uc]=ans[i][j]+1;
                }
            }
        }

        return ans;
    }
};