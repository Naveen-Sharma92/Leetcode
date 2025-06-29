class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int sum=0,m=0;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j = i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    m++;     
                }
            }
        }
        return m;
    }
};