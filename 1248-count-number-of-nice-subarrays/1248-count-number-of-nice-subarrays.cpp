class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd=0,n=nums.size(),ans=0;
        unordered_map<int,int>mpp;  // to store number of odds at indexs like prefix sum
        mpp[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1)
                odd++;
            int required=odd-k;
            ans+=mpp[required];
            mpp[odd]++;
        }
        return ans;
    }
};