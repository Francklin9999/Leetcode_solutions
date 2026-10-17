class Solution {
private:
    int digitSum(int num) {
        int sum{};

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        std::vector<pair<int, int>> vec(nums.size());

        for (auto i{0uz}; i < nums.size(); ++i) {
            vec[i] = make_pair(digitSum(nums[i]), i);
        }

        sort(vec.begin(), vec.end(), [&nums](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return nums[a.second] < nums[b.second];
            }

            return a.first < b.first;
        });

        std::vector<bool> visited(nums.size());
        int cycles{};

        for (auto i{0uz}; i < nums.size(); ++i) {
            if (visited[i]) continue;

            int j = i;
            int curr{};
            while (!visited[j]) {
                visited[j] = true;
                j = vec[j].second;
                ++curr;
            }

            cycles += curr - 1;
        }

        return cycles;
    }
};