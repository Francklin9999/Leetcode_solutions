class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> mapi;
        unordered_map<int, unordered_set<int>> mapj;
        map<pair<int, int>, unordered_set<int>> mapij;

        for (auto i{0uz}; i < board.size(); ++i) {
            for (auto j{0uz}; j < board[0].size(); ++j) {
                if (board[i][j] == '.') continue;

                if (mapi[i].count(board[i][j])) 
                    return false;
                else 
                    mapi[i].insert(board[i][j]);

                if (mapj[j].count(board[i][j]))
                    return false;
                else
                    mapj[j].insert(board[i][j]);

                if (mapij[pair<int, int>(i / 3, j / 3)].count(board[i][j]))
                    return false;
                else
                    mapij[pair<int, int>(i / 3, j / 3)].insert(board[i][j]);
            }
        }

        return true;
    }
};