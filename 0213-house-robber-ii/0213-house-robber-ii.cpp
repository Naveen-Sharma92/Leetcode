// class Solution {
// public:
//     int withoutfirst(vector<int>& nums){
//         int n = nums.size();
//         if (n == 2) 
//             return nums[1];
        
//         int prev2 = nums[1]; // Represents dp[i-2]
//         int prev1 = max(nums[1], nums[2]); // Represents dp[i-1]
        
//         for (int i = 3; i < n; i++) {
//             int curr = max(prev1, prev2 + nums[i]);
//             prev2 = prev1;
//             prev1 = curr;
//         }
        
//         return prev1;
//     }

//     int withoutlast(vector<int>& nums){
//         int n = nums.size();
//         if (n == 1) return nums[0];
        
//         int prev2 = nums[0]; // Represents dp[i-2]
//         int prev1 = max(nums[0], nums[1]); // Represents dp[i-1]
        
//         for (int i = 2; i < n-1; i++) {
//             int curr = max(prev1, prev2 + nums[i]);
//             prev2 = prev1;
//             prev1 = curr;
//         }
        
//         return prev1;
//     }
//     int rob(vector<int>& nums) {
//         if(nums.size()==1)
//             return nums[0];
//         return max(withoutfirst(nums),withoutlast(nums));
//     }
// };


// same above code but fewer lines so

class Solution {
public:
    // Single helper function to rob a linear range [start, end]
    int robRange(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        
        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start+1]);
        
        for (int i = start + 2; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // Scenario 1: Include first, exclude last (0 to n-2)
        // Scenario 2: Exclude first, include last (1 to n-1)
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};