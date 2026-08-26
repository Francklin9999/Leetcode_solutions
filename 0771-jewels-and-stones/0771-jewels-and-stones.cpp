class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<int> set;

        for (auto i{0uz}; i < jewels.size(); ++i) set.insert(jewels[i]);

        int sum{};
        
        for (auto i{0uz}; i < stones.size(); ++i) {
            sum += set.count(stones[i]) & 1;
        }

        return sum;
    }
};