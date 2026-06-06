class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1); // node,dis
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[k]=0;
        pq.push({0,k}); //dis, node
        while(!pq.empty()){
            int d= pq.top().first;
            int node= pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                if(dis[it.first]> d+it.second){
                    dis[it.first]= d+it.second;
                    pq.push({d+it.second, it.first});
                }
            }
        }
        dis[0]=-1;
        auto it = max_element(dis.begin(), dis.end());
        int max= *it;
        if(max==1e9)
            return -1;
        return max;
    }
};