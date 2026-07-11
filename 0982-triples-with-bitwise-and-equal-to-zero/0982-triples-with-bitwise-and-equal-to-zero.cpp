class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n= nums.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mpp[nums[i] & nums[j]]++;
            }
        }
        for(int i=0;i<n;i++){
            for(auto it:mpp){
                if((it.first & nums[i]) ==0)
                    ans+=it.second;
        }
        }
        return ans;
    }
};