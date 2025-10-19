// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int maximum= 1;
//         int max_element = nums[0];
//         int current =1;
//         for(int i=1;i<nums.size();i++){
//             if(nums[i-1]==nums[i])
//                 current++;
//             else
//                 current=1;
//             if(current>maximum){
//                 maximum = max(maximum,current);
//                 max_element = nums[i];
//             }
//         }
//         return max_element;
//     }
// };
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[n/2]==nums[0])
            return nums[0];
        if(nums[n/2]==nums[n-1])
            return nums[n-1];
        return nums[n/2];
    }
};