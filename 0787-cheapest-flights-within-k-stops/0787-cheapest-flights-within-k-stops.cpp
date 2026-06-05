class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m= flights.size();
        vector<int>dist(n,1e9);
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]}); // node,weights
        }
        
        queue<pair<int,pair<int, int>>> pq; // K,dist,node K is intermediate nodes
        pq.push({0,{0,src}});
        dist[src]=0;

        while(!pq.empty()){
            int K=pq.front().first;
            int d=pq.front().second.first;
            int node=pq.front().second.second;
            pq.pop();
            if(K>k )
                continue;
            for(auto it:adj[node]){
                if(dist[it.first]> d+ it.second){
                    dist[it.first] = d+it.second;
                    pq.push({K+1,{dist[it.first],it.first}});
                }
            }
        }
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
    }
};