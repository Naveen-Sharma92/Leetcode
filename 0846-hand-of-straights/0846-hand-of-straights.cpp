class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize != 0)
            return false;
        map<int,int>mpp;
        for(int i=0;i<n;i++)
            mpp[hand[i]]++;

        while(mpp.size()){
            int start=mpp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mpp[start+i]<=0)
                    return false;
                mpp[start+i]--;
                if(mpp[start+i] == 0)
                    mpp.erase(start+i);
            }
        }
        return true;
        
    }
};