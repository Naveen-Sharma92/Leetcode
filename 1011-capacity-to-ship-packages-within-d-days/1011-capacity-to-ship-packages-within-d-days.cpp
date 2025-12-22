class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());// as we need to load all type of weights
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2,d=0;
            long long s=0;
            for(int i=0;i<weights.size();i++){
                if(s+weights[i]>mid){
                    d++;
                    s=0;
                    i--; //as we does not load this package
                }
                else
                    s+=weights[i];
            }
            if(s>0)
                d++;
            if(d>days){
                low=mid+1;
            }
            else{
                high=mid-1;
            }

        }
        return low;
    }
};