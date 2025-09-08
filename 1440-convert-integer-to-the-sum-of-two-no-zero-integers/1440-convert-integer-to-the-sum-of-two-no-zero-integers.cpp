class Solution {
public:
bool check(int q){
    while(q!=0){
        if(q%10==0)
            return false;
        else
            q = q/10;
    }
    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        int x= ceil(n/2.0);
        int y = floor(n/2.0);
        while(!((check(x)) && (check(y)))){
            x--;
            y++;
        }
    return {x,y};
    }
};