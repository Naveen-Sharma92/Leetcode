class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int c=0,n=prices.size();
        int l=0,r=0;
        while(r<n){
            if(prices[r]<prices[l])
                l=r;
            c=max(c,prices[r]-prices[l]);
            r++;
        }
        return c;
    }
};