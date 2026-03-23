class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> queue;
        int ROWS = image.size();
        int COLS = image[0].size();
        int COLOR = image[sr][sc];
        vector<vector<int>> seen(image.size(), vector<int>(image[0].size()));
        vector<vector<int>> ajd = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue.push(pair(sr, sc));
        seen[sr][sc] = true;

        while (!queue.empty()) {
            auto& curr = queue.front();
            image[curr.first][curr.second] = color;

            for (int i = 0; i < ajd.size(); i++) {
                int row = curr.first + ajd[i][0];
                int col = curr.second + ajd[i][1];

                if (row >= 0 && row < ROWS && col >= 0 && col < COLS && image[row][col] == COLOR && !seen[row][col]) {
                    seen[row][col] = true;
                    queue.push(pair(row, col));
                }
            }
            queue.pop();

        }

        return image;
    }
};