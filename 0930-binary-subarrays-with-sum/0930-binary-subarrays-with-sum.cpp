// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int l=0,r=0,s=nums[0],c=0;
//         while(r<nums.size()){
//             if(s==goal){
//                 c++;
//                 r++;
//                 s+=nums[r];
//             }
//             else if(s<goal){
//                 r++;
//                 s+=nums[r];
//             }
//             else{
//                 s-=nums[l];
//                 l++;
//             }

//         }
//         while(l<nums.size()){
//             s-=nums[l];
//             l++;
//             if(s==goal)
//                 c++;
//         }
//         return c;
//     }
// };


// we do count(sum ≤ goal) - count(sum ≤ goal - 1)
// class Solution {
//     int no_of_sub(vector<int>& nums, int goal){
//         if (goal < 0) 
//             return 0;
//         int sum=0,l=0,r=0,cnt=0;
//         while(r<nums.size()){
//             sum+=nums[r];
//             while(sum>goal){
//                 sum-=nums[l];
//                 l++;
//             }
//             cnt+=(r-l+1);  //When the window [l … r] has sum ≤ goal. Every subarray that ends at r and starts anywhere from l to r is valid so not c++;

//             r++;
//         }
//         return cnt;
//     }
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         return no_of_sub(nums,goal) - no_of_sub(nums,goal-1) ;
//     }
// };


class Solution{
    public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefsum=0,n=nums.size(),ans=0;
        unordered_map<int ,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            prefsum+=nums[i];
            int remove_needed=prefsum-goal;
            ans+=mpp[remove_needed];
            mpp[prefsum]++;
        }
        return ans;
    }
};

