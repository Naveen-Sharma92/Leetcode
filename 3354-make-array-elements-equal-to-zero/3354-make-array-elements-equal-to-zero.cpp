// class Solution {
// public:
//     int countValidSelections(vector<int>& nums) {
//         int c=0;
//         float s=0,so=0;
//         for(auto it:nums){
//             s+=it;
//         }
//         for(auto it:nums){
//             so+=it;
//             if(it==0 && so==floor(s/2))
//                 c+=2;
//             if(it==0 && (so==floor(s/2-1) || so==floor(s/2+1)))
//             c+=1;
//         }
//         return c;
//     }
// };

//above is wrong


class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int left=0;
        int right=sum;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(left==right)
                    ans+=2;
                else if(abs(left-right)==1)
                    ans+=1;
            }
            left+=nums[i];
            right-=nums[i];
        }
        return ans;
    }
};