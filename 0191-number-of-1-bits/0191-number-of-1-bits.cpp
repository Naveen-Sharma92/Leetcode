class Solution {
public:
    int hammingWeight(int n) {
        int x=n,c=0;
        while(x>0){
            x= x & (x-1);
            c++;
        }
        return c;
    }
};