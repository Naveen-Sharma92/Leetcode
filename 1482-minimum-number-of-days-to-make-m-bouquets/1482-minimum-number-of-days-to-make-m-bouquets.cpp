class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (1LL*m*k))
            return -1;
        int n=bloomDay.size();
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2,b=0,c=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid)
                    c++;
                else
                    c=0;
                if(c==k){
                    b++;
                    c=0;
                }
            }
            if(b<m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};