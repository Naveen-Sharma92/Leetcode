class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1000000007;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});  // node,dis
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<long long>dis(n, LLONG_MAX);  // dis is long long node is int
        vector<long long>ways(n,0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0}); //dis, node

        while(!pq.empty()){
            long long d= pq.top().first;
            int node= pq.top().second;
            pq.pop();

            if(d > dis[node]) 
                continue;
            for(auto it:adj[node]){
                if(dis[it.first]==d+it.second)
                    ways[it.first] = (ways[node]+ways[it.first])% MOD;  //fraw the diagram in notebook see it works only 
                else if(dis[it.first]> d+it.second){
                    dis[it.first]= d+it.second;
                    ways[it.first]=ways[node];
                    pq.push({d+it.second, it.first});
                }
                
            }
        }
        
        return ways[n-1]%MOD;
    }
};