class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
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
                        return high;
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
        return -1;
    }
};