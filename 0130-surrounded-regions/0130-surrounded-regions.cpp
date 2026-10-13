class Solution {
static constexpr int nei[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        std::queue<pair<int, int>> queue;
        vector<pair<int, int>> pos;

        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
                if (board[i][j] != 'O') continue;

                bool valid{true};
                pos.clear();
                queue.emplace(i, j);

                while (!queue.empty()) {
                    auto [row, col] = queue.front();
                    queue.pop();

                    if (row == 0 || row == m - 1 || col == 0 || col == n - 1) {
                        valid = false;
                    }

                    board[row][col] = 'V';
                    pos.emplace_back(row, col);

                    for (int k{0}; k < 4; ++k) {
                        auto x = nei[k][0] + row;
                        auto y = nei[k][1] + col;

                        if (x < 0 || x == m || y < 0 || y == n || board[x][y] != 'O') continue;

                        board[x][y] = 'V';
                        pos.emplace_back(x, y);
                        queue.emplace(x, y);
                    }
                }

                if (valid) {
                    for (auto z{0uz}; z < pos.size(); ++z) {
                        board[pos[z].first][pos[z].second] = 'X';
                    }
                }
            }
        }

        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
                if (board[i][j] == 'V') board[i][j] = 'O';
            }
        }
    }
};