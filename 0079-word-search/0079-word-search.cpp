class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> ajd = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (helper(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }

    bool helper(vector<vector<char>>& board, string& word, int x, int y, int idx) {
        if (idx == word.size()) {
            return true;
        }
        
        if (x >= ROWS || x < 0 || y >= COLS || y < 0 || board[x][y] != word[idx]) return false;
        board[x][y] = '#';

        for (int i = 0; i < ajd.size(); i++) {
            if (helper(board, word, x + ajd[i][0], y + ajd[i][1], idx + 1)) return true;
        }

        board[x][y] = word[idx];
        return false;
    }
};