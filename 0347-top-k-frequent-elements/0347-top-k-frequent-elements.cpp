class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<pair<int,int>>v;
        for(auto it:nums)
            mpp[it]++;
        for(auto it:mpp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end()); //ascending order soritng
        vector<int>ans(k);
        int n=v.size();
        for(int i=0;i<k;i++){
            ans[i]=v[n-1-i].second;
        }
        return ans;
        
    }
};