class Solution {
public:
    void bfs(int i,vector<vector<int>>& isConnected, vector<int>& visited){
        queue<int>q;
        q.push(i);
        visited[i]=1;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[a][j]==1){
                    if(visited[j]==0){
                        visited[j]=1;
                        q.push(j);
                    }
                }
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> visited(n, 0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                bfs(i,isConnected,visited);
            }
        }
        return ans;

    }
};