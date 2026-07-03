class Solution {
public:
    int withoutfirst(vector<int>& nums){
        int n = nums.size();
        if(n==0)
            return -1;
        if (n == 2) 
            return nums[1];
        
        int prev2 = nums[1]; // Represents dp[i-2]
        int prev1 = max(nums[1], nums[2]); // Represents dp[i-1]
        
        for (int i = 3; i < n; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }

    int withoutlast(vector<int>& nums){
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int prev2 = nums[0]; // Represents dp[i-2]
        int prev1 = max(nums[0], nums[1]); // Represents dp[i-1]
        
        for (int i = 2; i < n-1; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        return max(withoutfirst(nums),withoutlast(nums));
    }
};