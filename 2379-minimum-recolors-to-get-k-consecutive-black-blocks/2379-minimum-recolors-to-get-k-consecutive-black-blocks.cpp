class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int black{}, white{};
        int res{INT_MAX};

        for (int i{0}; i < k; ++i) {
            if (blocks[i] == 'W') ++white;
            else ++black;
        }

        res = std::min(res, white);

        for (size_t l{0}, i = k; i < blocks.size(); ++i, ++l) {
            if (blocks[l] == 'W') --white;
            else --black;

            if (blocks[i] == 'W') ++white;
            else ++black;
            
            res = std::min(res, white);
        }

        return res;
    }
};