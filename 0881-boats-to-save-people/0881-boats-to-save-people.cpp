class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        int l{0};
        int r = people.size() - 1;
        int count{0};
        int maxPeople{2};

        while (l <= r) {
            int curr{limit};
            int currPeople{0};
            while (r >= l && currPeople < maxPeople && curr - people[r] >= 0) {
                curr -= people[r];
                r--;
                currPeople++;
            }
            while (l < r && currPeople < maxPeople && curr - people[l] >= 0) {
                curr -= people[l];
                l++;
                currPeople++;
            }
            count++;
        }

        return count;
    }
};