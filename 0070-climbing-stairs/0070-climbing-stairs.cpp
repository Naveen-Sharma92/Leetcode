// with dp

// class Solution {
// public:
//     int dp(int n, unordered_map<int,int>& mpp){
//         if(n==1)
//             return 1;
//         if(n==2)
//             return 2;
//         if(mpp[n]!=0)
//             return mpp[n];
//         mpp[n]= dp(n-1,mpp)+ dp(n-2,mpp);
//         return mpp[n];
//     }
//     int climbStairs(int n) {
//         unordered_map<int,int>mpp;
//         mpp[1]=1;
//         mpp[2]=2;
//         return dp(n,mpp);
//     }
// };


// simple array
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        vector<int>v(n+1,0);
        v[1]=1;
        v[2]=2;
        for(int i=3;i<n+1;i++)
            v[i]= v[i-1]+ v[i-2];
        return v[n];
    }
};