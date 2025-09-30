// class Solution {
// public:
//     int triangularSum(vector<int>& nums) {
//         while(1){
//             vector<int>v;
//             for(int i=0;i<nums.size()-1;i++){
//                 v.push_back((nums[i]+nums[i+1])%10);
//             }
//             if(nums.size()==1)
//                 return nums[0];
//             nums.clear();
//             nums=v;
            
//         }
//     }
// };

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n>1){
            for(int i=0;i<n-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            n--;
        }
        return nums[0];
            
        }
};