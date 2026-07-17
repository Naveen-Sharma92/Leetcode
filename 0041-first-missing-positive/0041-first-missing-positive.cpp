class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int compare =1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==compare)
                compare++;
            else if(nums[i]>compare)
                return compare;
        }
        return compare;
    }
};