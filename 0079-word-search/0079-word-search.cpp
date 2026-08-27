class Solution {
public:
    bool rec(vector<vector<char>>& board, string word,
             string &temp, vector<vector<bool>>& vis,
             int r, int c, int index) {

        int m = board.size();
        int n = board[0].size();

        if(temp == word)
            return true;

        if(r >= m || c >= n || r < 0 || c < 0 || index >= word.size())
            return false;

        // If current cell doesn't match, stop
        if(board[r][c] != word[index] || vis[r][c] == true)
            return false;

        vis[r][c] = true;
        temp.push_back(word[index]);

        if(rec(board, word, temp, vis, r-1, c, index+1))
            return true;

        if(rec(board, word, temp, vis, r, c-1, index+1))
            return true;

        if(rec(board, word, temp, vis, r, c+1, index+1))
            return true;

        if(rec(board, word, temp, vis, r+1, c, index+1))
            return true;

        // Backtrack
        vis[r][c] = false;
        temp.pop_back();

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        string temp = "";

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {

                if(rec(board, word, temp, vis, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};