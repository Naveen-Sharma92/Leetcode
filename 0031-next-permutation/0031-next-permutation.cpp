class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int l = -1;

        // Find rightmost pivot
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                l = i - 1;
            }
        }

        // Already largest permutation
        if(l == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find rightmost element greater than pivot
        int r = n - 1;

        while(nums[r] <= nums[l])
            r--;

        swap(nums[l], nums[r]);

        // Reverse suffix
        reverse(nums.begin() + l + 1, nums.end());
    }
};