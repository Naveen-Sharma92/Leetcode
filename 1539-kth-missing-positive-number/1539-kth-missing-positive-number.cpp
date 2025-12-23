class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int c=0,j=1;
        bool l=true;
        while(1){
            for(int i=0;i<arr.size();i++){
                if(arr[i]==j){
                    l=false;
                    break;
                }
            }
            if(l){
                c++;
            }
            if(c==k){
                return j;
            }
            j++;
            l=true;
        }
        return j;
    }
};