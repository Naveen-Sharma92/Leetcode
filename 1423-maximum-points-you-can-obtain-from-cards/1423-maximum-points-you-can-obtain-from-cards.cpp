class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        long long lsum=0,rsum=0,maxsum=0;
        int rindex=n-1;
        for(int i=0;i<k;i++)
            lsum = lsum + cardPoints[i];
        maxsum=lsum;
        for(int i=k-1;i>=0;i--){
            lsum=lsum-cardPoints[i];
            rsum=rsum+cardPoints[rindex];
            maxsum=max(maxsum,lsum+rsum);
            rindex--;
        }
        return maxsum;
    }
};