// class Solution {
// public:
//     bool dfs(int i,vector<vector<int>> & adj,vector<int> & visited,vector<int>& pathvisited){
//         visited[i]=1;
//         pathvisited[i]=1;
//         for(int j=0;j<adj[i].size();j++){
//             if(!visited[adj[i][j]]){
//                 if(dfs(adj[i][j],adj,visited,pathvisited)==true)
//                     return true;
//             }// i got error because of it has else if misplaces with wrong if
//             else if(pathvisited[adj[i][j]]==1)
//                 return true;
//         }

//         pathvisited[i]=0;
//         return false;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         //using dfs directed graph cycle detection
//         int n=prerequisites.size();
//         vector<vector<int>>adj(numCourses);
//         vector<int> visited(numCourses,0);
//         vector<int> pathvisited(numCourses,0);
//         for(int i=0;i<n;i++){
//                 adj[prerequisites[i][1]].push_back(prerequisites[i][0]); //i got error here 0 ki jagah 1 nahi likhsakte
//         }
//         for(int i=0;i<numCourses;i++){
//             if(!visited[i]){
//                 if(dfs(i,adj,visited,pathvisited)==true)
//                     return false;
//             }
//         }
//         return true;
//     }
// };

// now using toposort
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        int ans=0;

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(auto it:adj[n]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
            ans++;
        }

        
        if(ans==numCourses)
            return true;
        else
            return false;
    }
};