//after doing 221. Maximal Square as they are same
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n=matrix[0].size();
        vector<int>prev(n,0);
        int count=0;
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0) // i mistook as char so i got wrong ans
                    continue;
                else{
                    int upleft=0,up=0,left=0;
                    if(j-1>=0 && i-1>=0)
                        upleft=prev[j-1];
                    if(j-1>=0)
                        left=curr[j-1];
                    if(i-1>=0)
                        up=prev[j];
                    curr[j]=min(upleft,min(up,left))+1;
                    count=count+curr[j]; // only this change as we are selecting the square whose bottom left is this i and j
            }
            }
            prev=curr;
        }
        return count;
    }
};