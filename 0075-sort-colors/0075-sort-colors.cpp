// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         //dutch nationla flag algorithm
//         int low=0,mid =0,n=nums.size(),i=0;
//         int high = n-1;
//         while(i<n){
//             if(nums[i]==0){
//                 low++;
//                 mid++;
//             }
//             else if(nums[i]==1)
//                 mid++;
//             else
//                 high--;
//             i++;
//         }
//         for(int i=0;i<n;i++){
//             if(i<low)
//             nums[i]=0;
//             else if(i<mid)
//             nums[i]=1;
//             else
//             nums[i]=2;
//             cout<<nums[i]<<",";
//         }

//     }
// };
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch nationla flag algorithm
        int low=0,mid =0;
        int high = nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
                mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }

    }
};