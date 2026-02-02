class Solution {
public:
    static bool comp(vector<int> &a ,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0,last_endtime=INT_MIN;;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<last_endtime){
                cnt++;
            }
            else{
                last_endtime=intervals[i][1];
            }
        }

        return cnt;
    }
    
};