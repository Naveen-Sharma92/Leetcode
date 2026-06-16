class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini=nums[0],maxi=nums[0];
        for(auto it:nums){
            mini = min(mini,it);
            maxi = max(maxi,it);
        }
        return 1LL * k *(maxi-mini);
    }
};