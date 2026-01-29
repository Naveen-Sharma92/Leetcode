//brute
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> temp;
        temp.resize(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            temp[i][j]=matrix[i][j];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            matrix[i][j]=temp[n-j-1][i];
        }
        return;
    }
};