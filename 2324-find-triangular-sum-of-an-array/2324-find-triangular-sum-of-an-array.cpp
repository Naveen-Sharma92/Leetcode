class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(1){
            vector<int>v;
            for(int i=0;i<nums.size()-1;i++){
                v.push_back((nums[i]+nums[i+1])%10);
            }
            if(nums.size()==1)
                return nums[0];
            nums.clear();
            nums=v;
            
        }
    }
};