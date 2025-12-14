class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        int mid=(low+high)/2;
        while(high>=low){
            if(target==nums[mid])
                return mid;
            else if(target>nums[mid])
                low=mid+1;
            else
                high=mid-1;
            mid=(low+high)/2;
        }
        return -1;
        
    }
};