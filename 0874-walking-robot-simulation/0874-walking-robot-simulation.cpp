class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direction{1};
        int x{0}, y{0};
        int total{};

        set<pair<int, int>> set;

        for (auto& obj : obstacles) {
            set.insert({obj[0], obj[1]});
        }

        for (auto i = 0uz; i < commands.size(); ++i) {
            if (commands[i] < 0) {
                if (commands[i] == -2) direction++;
                if (commands[i] == -1) direction--;
                direction = (direction + 4) % 4;
            } else {
                if (direction == 0) {
                    while (commands[i]-- > 0 && !set.contains({x + 1, y})) {
                        x++;
                    }
                } else if (direction == 2) {
                    while (commands[i]-- > 0 && !set.contains({x - 1, y})) {
                        x--;
                    }
                } else if (direction == 1) {
                    while (commands[i]-- > 0 && !set.contains({x, y + 1})) {
                        y++;
                    }
                } else if (direction == 3) {
                    while (commands[i]-- > 0 && !set.contains({x, y - 1})) {
                        y--;
                    }
                }
            }

            total = std::max(total, static_cast<int>(std::pow(std::abs(x), 2) + std::pow(std::abs(y), 2)));
        }

        return total;
    }
};