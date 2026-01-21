// like hashing in the problem binary subarray with sum
// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int odd=0,n=nums.size(),ans=0;
//         unordered_map<int,int>mpp;  // to store number of odds at indexs like prefix sum
//         mpp[0]=1;
//         for(int i=0;i<n;i++){
//             if(nums[i]%2==1)
//                 odd++;
//             int required=odd-k;
//             ans+=mpp[required];
//             mpp[odd]++;
//         }
//         return ans;
//     }
// };

// count where odds are grater than k and grater than k-1 and subtrat them
class Solution {

public:
    int oddsf(vector<int>& nums, int k){
        int l=0,r=0,ans=0,cnt=0;
        while(r<nums.size()){
            if(nums[r]%2==1)
                cnt++;
            while(cnt>k){
                if(nums[l]%2==1)
                    cnt--;
                l++;
            }
            ans+=(r-l+1);
            r++;

        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return oddsf(nums,k)-oddsf(nums,k-1);
    }
};