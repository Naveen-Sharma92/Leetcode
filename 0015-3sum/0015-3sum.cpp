class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1]) {  // duplicate
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int s=nums[i]+nums[j]+nums[k];

                if(s==0){
                    v.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--; // as we not want duplicate;
                    while(j<k &&nums[j]==nums[j-1] )
                        j++;
                    while(j<k && nums[k]==nums[k+1])
                        k--;
                }
                else if(s>0)
                    k--;
                else
                    j++;
            }
        }

        return v;
    }
};