class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size()-2;
        int a=0;
        for(int i=0;i<nums.size();i++){
            a=a^nums[i];
        }
        for(int i=0;i<n;i++){
            a=a^i;
        }
        int k = a & -a;

        int a1 = 0, b1 = 0;
    for (int i : nums) {
        if (i & k) 
            a1 ^= i;
        else          
            b1 ^= i;
    }
    for (int i = 0; i < n; ++i) {
        if (i & k) 
            a1 ^= i;
        else          
            b1 ^= i;
    }

    return {a1, b1};
    }
};