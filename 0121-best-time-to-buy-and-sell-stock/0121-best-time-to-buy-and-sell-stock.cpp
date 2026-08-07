// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int c=0,n=prices.size();  //sliding window
//         int l=0,r=0;
//         while(r<n){
//             if(prices[r]<prices[l])
//                 l=r;
//             c=max(c,prices[r]-prices[l]);
//             r++;
//         }
//         return c;
//     }
// };

//revise
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=0,ans=0;
        int n= prices.size();
        while(r<n){
            if(prices[r]<prices[l])
                l=r;
            ans= max(ans,prices[r]-prices[l]);
            r++;
        }
        return ans;
    }
};