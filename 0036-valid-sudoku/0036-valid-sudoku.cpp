class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_map<char,int>m,n;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.')
                    m[board[i][j]]++;
            }
            for(auto it:m){
                if(it.second>1)
                    return false;
            }
            for(int j=0;j<9;j++){
                if(board[j][i]!='.')
                    n[board[j][i]]++;
            }
            for(auto it:n){
                if(it.second>1)
                    return false;
            }
        }
    for (int box_row = 0; box_row < 9; box_row += 3) {
    for (int box_col = 0; box_col < 9; box_col += 3) {
        unordered_set<char> box_seen;
        for (int i = box_row; i < box_row + 3; ++i) {
            for (int j = box_col; j < box_col + 3; ++j) {
                if (board[i][j] != '.') {
                    if (box_seen.count(board[i][j])) {
                        return false;
                    }
                    box_seen.insert(board[i][j]);
                }
            }
        }
    }
}
        return true;
    }
};