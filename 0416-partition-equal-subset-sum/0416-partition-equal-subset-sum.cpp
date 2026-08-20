class Solution {
public:
    bool dpp(vector<int>& nums,int target){
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(target+1,false)); //target +1 because we need 0 also;
        for(int i=0;i<n;i++){
            dp[i][0]=true; // target 0 is can be achieve by all index of 1st row
        }
        if(nums[0] <= target) // base case but only if nums[0]<target otherwise runtime error
            dp[0][nums[0]] = true;

        for(int i= 1;i<n;i++){ //beacsue i=0 already above it is for index
            for(int j=1;j<=target;j++){ // j is the currecnt sum target
                bool notTake= dp[i-1][j]; // we are going from index 1 to n-1
                bool take = false;
                if(nums[i]<=j)
                    take= dp[i-1][j-nums[i]];
                dp[i][j]=take | notTake;
            }
        }
        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2 ==1)
            return false;
        return dpp(nums,sum/2);
    }
};