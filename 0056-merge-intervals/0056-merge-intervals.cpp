class Solution {
public:
    static bool comp (const vector<int> &a,const vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        if(n<=1)
            return intervals;
        int i=0;
        while(i<n-1){
            if(intervals[i][1]<intervals[i+1][0]){
                v.push_back(intervals[i]);
                i++;
            }
            else{
                int start=intervals[i][0];
                int end=intervals[i][1];
                while(i<n-1 && end>=intervals[i+1][0] ){   // not do intervals[i][1] because it will compare consecutives not the biggest end we got
                    end=max(intervals[i+1][1],end);
                    i++;
                }
                v.push_back({start,end});
                i++;
            }

        }
        if(i == n-1)
            v.push_back(intervals[n-1]);

        return v;
    }
};