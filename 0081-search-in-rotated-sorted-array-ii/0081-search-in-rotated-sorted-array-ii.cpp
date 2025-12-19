class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if((nums[mid]==nums[low]) && (nums[mid]==nums[high]) ){
                if(nums[mid]==target)
                    return true;
                else{
                    low=low+1;
                    high=high-1;
                }

            }
           else if(nums[mid]==target)
                return true;
            else if(nums[mid]>nums[high]){
                if(target>nums[mid])
                    low=mid+1;
                else{
                    if(target>nums[high]){
                        high=mid-1;
                    }
                    else if(target<nums[high])
                        low=mid+1;
                    else
                        return true;
                }
            }
            else{
                 if(target>nums[mid]){
                    if(target>nums[high]){
                        high=mid-1;
                    }
                    else if(target<nums[high])
                        low=mid+1;
                    else
                        return high;
                }
                else{
                   high=mid-1;

                 }
        }
        }
        return false;
     
    }
};