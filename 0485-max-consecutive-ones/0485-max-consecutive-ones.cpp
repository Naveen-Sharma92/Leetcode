class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int max=0;
      int c=0,n=nums.size();
      for(int i =0;i<n;i++){
        
        if(nums[i]==1){
            c++;
        }
        else
            c=0;
        if(max<c)
            max=c;
      } 
      return max; 
    }
};