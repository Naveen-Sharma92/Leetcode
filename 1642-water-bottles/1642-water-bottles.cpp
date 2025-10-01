class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
      int ans=numBottles;
      while(numBottles>=numExchange){
        int r = numBottles%numExchange;
        numBottles/=numExchange;
        ans+=numBottles;
        numBottles+=r;
      }
    return ans;
        
    }
};