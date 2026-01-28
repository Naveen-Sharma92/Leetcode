class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt=0,n=nums.size(),i=0,j=0;
        while(i<n-1){
            cnt++;
            if(i+nums[i]>=(n-1))
                return cnt;
            int maxi=0,best_index=0;
            for(int j=i+1;j<=(i+nums[i]);j++){
                if(maxi<(j+nums[j])){
                    maxi=j+nums[j];
                    best_index=j;
                }
            }
            i=best_index;
        }
        return cnt;
    }
};