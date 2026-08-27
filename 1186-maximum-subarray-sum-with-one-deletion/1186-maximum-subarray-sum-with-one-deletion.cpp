class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int state[3] = {arr[0], arr[0], arr[0]};

        for (auto i{1uz}; i < arr.size(); ++i) {
            state[0] = std::max(state[1], state[0] + arr[i]);
            state[1] = std::max(state[1] + arr[i], arr[i]);
            state[2] = std::max({state[2], state[1], state[0]});
        }

        return state[2];
    }
};