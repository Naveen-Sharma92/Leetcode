class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& visited){
        int m=board.size();
        int n=board[0].size();
        bool y=true;
        vector<pair<int,int>>v;
        queue<pair<int,int>>q;
        q.push({i,j});
        v.push_back({i, j});
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
                    if(board[ur][uc]=='O'&& visited[ur][uc]==0){
                        visited[ur][uc]=1;
                        v.push_back({ur,uc});
                        q.push({ur,uc});
                    }

                }
                else
                    y=false;
            }
        }
        if(y){
            for(auto it:v){
                board[it.first][it.second]='X';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]  && board[i][j]=='O'){
                    bfs(i,j,board,visited);
                }
            }
        }
        return;
    }
};