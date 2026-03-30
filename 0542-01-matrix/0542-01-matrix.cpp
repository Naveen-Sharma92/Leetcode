// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m=mat.size();
//         int n=mat[0].size();
//         vector<vector<int>>ans(m,vector<int>(n,-1)); // this will work as visited array as initial -1;
//         queue<pair<int,pair<int,int>>>q; // value, int i, intj
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(mat[i][j]==0){
//                     q.push({0,{i,j}});
//                     ans[i][j]=0;
//                 }
//             }
//         }
//         while(!q.empty()){
//             int a=q.front().first;
//             int i=q.front().second.first;
//             int j=q.front().second.second;
//             q.pop();
//             int dr[]={-1,0,0,1};
//             int dc[]={0,-1,1,0};
//             for(int k=0;k<4;k++){
//                 int ur=i+dr[k];
//                 int uc=j+dc[k];
//                 if(ur>=0 && ur<m && uc>=0 && uc<n && ans[ur][uc]==-1){
//                     q.push({a+1,{ur,uc}});
//                     ans[ur][uc]=a+1;
//                 }
//             }
//         }
//         return ans;
//     }
// };

//space complexity optimise
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1)); // this will work as visited array as initial -1;
        queue<pair<int,int>>q; // int i, intj
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
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
                    ans[ur][uc]=ans[i][j] +1; // we do not need to store as answer is parent +1;
                }
            }
        }
        return ans;
    }
};