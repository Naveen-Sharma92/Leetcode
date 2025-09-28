class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1;i<=60;i++){
            long long x = (long long)num1-(1LL*i*num2);
            long long c = x,count=0;
            while(c>0){
                c= c & (c-1);
                count++;
            }
            if (x > 0 && count <= i && x >= i) {
                return i;
            }
        }
        return -1;
    }
};