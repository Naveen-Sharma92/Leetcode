class DisJoint {
public:
    vector<int> sizes,parent;
    DisJoint(int n){
        sizes.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findupar(int node){
        if(parent[node]==node)
            return node;
        else
            return parent[node]=findupar(parent[node]);  // for path compresiion we do parent[node] = .....

    }

    void unionbysize(int u,int v){
        int uu = findupar(u);
        int uv = findupar(v);

        if(uu==uv)
            return;
        if(sizes[uv]> sizes[uu]){
            parent[uu]= uv;
            sizes[uv]+=sizes[uu];
        }
        else{
            parent[uv]=uu;
            sizes[uu]+=sizes[uv];
        }
    }
};

//using dsu
// class Solution {
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         int a= connections.size();
//         if(a<n-1)
//             return -1;
//         int c=0;
//         vector<int>vis(n,0);
//         DisJoint ds(n);
//         for(auto it: connections){
//             ds.unionbysize(it[0],it[1]);
//         }
//         for(int i=0;i<n;i++){
//             if(ds.parent[i]==i)
//                 c++;
//         }
//         return c-1;
//     }
// };

//using simple traversal
class Solution {
public:
void dfs(int i, vector<int>& vis,vector<vector<int>>& adj){
    vis[i]=1;
    for(auto it: adj[i]){
        if(vis[it]==0)
            dfs(it,vis,adj);
    }
    return;
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        int a= connections.size();
        if(a<n-1)
            return -1;
        int c=0;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); // this i miss so got error 
        }

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,adj);
                c++;
            }
        }
        return c-1;
    }
};