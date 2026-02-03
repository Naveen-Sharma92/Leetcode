// I GOT IT WRONG IN LOGIC
// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         vector<vector<int>>ans;

//         int n=intervals.size();
//         int lastend=intervals[0][1];
//         bool y=true;
//         for(int i=0;i<n;i++){
//             if(lastend > newInterval[0]){
//                 int a= min(newInterval[0],intervals[i][0]);
//                 int b= max(newInterval[1],intervals[i][1]);
//                 lastend=b;
//                 ans.push_back({a,b});
//             }
//             else if(lastend<=intervals[i][1]){
//                 lastend=intervals[i][1];
//                 ans.push_back(intervals[i]);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;

        int n=intervals.size();
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
         ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};