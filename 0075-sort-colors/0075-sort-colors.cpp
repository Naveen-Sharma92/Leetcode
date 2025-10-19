class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch nationla flag algorithm
        int low=0,mid =0;
        int high = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                low++;
                mid++;
            }
            else if(nums[i]==1)
                mid++;
            else
                high--;
        }
        for(int i=0;i<nums.size();i++){
            if(i<low)
            nums[i]=0;
            else if(i<mid)
            nums[i]=1;
            else
            nums[i]=2;
            cout<<nums[i]<<",";
        }

    }
};