class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> jumps;

        for (int stone : stones) jumps[stone] = {};

        jumps[0] = {0};

        for (auto i{0uz}; i < stones.size(); ++i) {
            if (jumps[stones[i]].empty()) continue;
            for (auto jump : jumps[stones[i]]) {
                if (jump - 1 > 0 && jumps.count(jump + stones[i] - 1))
                    jumps[jump + stones[i] - 1].insert(jump - 1);

                if (jump > 0 && jumps.count(jump + stones[i]))
                    jumps[jump + stones[i]].insert(jump);

                if (jumps.count(jump + stones[i] + 1))
                    jumps[jump + stones[i] + 1].insert(jump + 1);
            }
        }

        return !jumps[stones.back()].empty();
    }
};