// // first attemp when i tries to use a see claude why i am wrong with example
// class Solution {
// public:
//     bool bfs(int i,vector<vector<int>>& graph,vector<int>& visited,int & a){
//         queue<int>q;
//         q.push(i);
//         visited[i]=a;
//         a*=-1;
//         while(!q.empty()){
//             int j=q.front();
//             q.pop();
//             for(int k=0;k<graph[j].size();k++){
//                 if(visited[graph[j][k]]==0){
//                     visited[graph[j][k]]=a;
//                     q.push(graph[j][k]);
//                 }
//                 else if(visited[graph[j][k]]== visited[j])
//                     return false;

//             }
//             a*=-1;
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int m=graph.size();
//         vector<int>visited(m,0);
//         int a=1;
//         for(int i=0;i<m;i++){
//             if(visited[i]==0){
//                 bool ans =bfs(i,graph,visited,a);
//                 if(ans==false)
//                     return false;
//             }
//         }
//         return true;
//     }
// };

// use the node itself instead of a
class Solution {
public:
    bool bfs(int i,vector<vector<int>>& graph,vector<int>& visited){
        queue<int>q;
        q.push(i);
        visited[i]=1;
        while(!q.empty()){
            int j=q.front();
            q.pop();
            for(int k=0;k<graph[j].size();k++){
                if(visited[graph[j][k]]==0){
                    visited[graph[j][k]]=-visited[j];
                    q.push(graph[j][k]);
                }
                else if(visited[graph[j][k]]== visited[j])
                    return false;

            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int>visited(m,0);
        int a=1;
        for(int i=0;i<m;i++){
            if(visited[i]==0){
                bool ans =bfs(i,graph,visited);
                if(ans==false)
                    return false;
            }
        }
        return true;
    }
};