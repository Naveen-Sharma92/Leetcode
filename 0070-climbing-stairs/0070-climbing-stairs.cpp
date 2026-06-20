class Solution {
public:
    int dp(int n, unordered_map<int,int>& mpp){
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(mpp[n]!=0)
            return mpp[n];
        mpp[n]= dp(n-1,mpp)+ dp(n-2,mpp);
        return mpp[n];
    }
    int climbStairs(int n) {
        unordered_map<int,int>mpp;
        mpp[1]=1;
        mpp[2]=2;
        return dp(n,mpp);
    }
};