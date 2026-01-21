class Solution {
public:
    int lessf(vector<int>& nums, int k){
        unordered_map<int ,int>mpp;
        int r=0,l=0,cnt=0,n=nums.size();
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)
                    mpp.erase(nums[l]);
                l++;
            }
            cnt+=(r-l+1);
            r++;

        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return lessf(nums,k)-lessf(nums,k-1);
    }
};