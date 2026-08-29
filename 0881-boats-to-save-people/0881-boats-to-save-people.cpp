class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int l{}, r = people.size() - 1, res{};

        while (l <= r) {
            int curr{};
            int p{2};

            while (p > 0 && r >= l && curr + people[r] <= limit) {
                curr += people[r--];
                --p;
            }

            while (p > 0 && l <= r && curr + people[l] <= limit) {
                curr += people[l++];
                --p;
            }

            ++res;
        }

        return res;
    }
};