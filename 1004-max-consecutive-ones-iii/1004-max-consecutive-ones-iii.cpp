// better approch
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int zero = 0;
//         int max_count =0;
//         int n = nums.size();
//         int l =0,r;
//         for(r=0;r<n;r++){
//             if(nums[r]== 0)
//                 zero++;
//             while(zero>k && l<n){
//                 if(nums[l]==0)
//                     zero--;
//                 l++;
//             }
//             if(max_count < (r-l+1)){
//                 max_count = (r-l+1);
//             }
//         }
//         return max_count;
        
//     }
// };


//best approch
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0;
        int max_count =0;
        int n = nums.size();
        int l =0,r=0;
        while(r<n){
            if(nums[r]==0)
                zero++;
            if(zero>k){
                if(nums[l]==0)
                    zero--;
                l++;
            }
            if(zero<=k)
                max_count = max(max_count,r-l+1);

            r++;
        }
        return max_count;
        
    }
};