class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        size_t rows = boxGrid.size();
        size_t cols = boxGrid[0].size();
        
        vector<vector<char>> result;

        for (auto i = 0uz; i < boxGrid.size(); ++i) {
            size_t pos{};
            for (auto j = 0uz; j < boxGrid[i].size(); ++j) {
                if (boxGrid[i][j] == '.') {
                    swap(boxGrid[i][pos], boxGrid[i][j]);
                    pos++;
                } else if (boxGrid[i][j] == '*') {
                    pos = j + 1;
                }
            }
        }

        for (auto j = 0uz; j < boxGrid[0].size() ; ++j) {
            vector<char> tmp;
            for (auto i = boxGrid.size(); i-- > 0;) {
                tmp.push_back(boxGrid[i][j]);
            }

            result.push_back(tmp);
        }

        return result;
    }
};