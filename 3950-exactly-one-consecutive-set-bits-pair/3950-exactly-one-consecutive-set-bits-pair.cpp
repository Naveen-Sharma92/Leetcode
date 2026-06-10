class Solution {
public:
    bool consecutiveSetBits(int n) {
        int c=0;
        while(n>0){
            if((n & 3) == 3)
                c++;
            n = n>>1;
        }
        return c==1;
    }
};