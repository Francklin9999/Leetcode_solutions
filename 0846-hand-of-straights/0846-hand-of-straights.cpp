class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        
        unordered_map<int, int> count;

        for (int i = 0; i < hand.size(); i++) {
            count[hand[i]]++;
        }

        sort(hand.begin(), hand.end());

        for (int i = hand.size() - 1; i >= 0; i--) {
            if (count[hand[i]] == 0) continue;
            int idx = hand[i]; 
            for (int j = 0; j < groupSize; j++) {
                auto curr = count.find(idx - j);
                if (curr != count.end() && curr->second > 0){
                    curr->second--;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};