class Solution {
public:
    int findMin(vector<int>& nums) {
        int high=nums.size()-1,low=0,min=INT_MAX;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(nums[mid]<min){
                min=nums[mid];
            }
            if(nums[mid]<nums[high]){
                high=mid-1;
            }
            else{
                low=low+1;
            }
        }
        return min;
    }
};