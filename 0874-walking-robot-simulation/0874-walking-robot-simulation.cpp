class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direction{1};
        int x{};
        int y{};
        int max{0};

        set<pair<int, int>> obstacle;
        
        for (auto i = 0uz; i < obstacles.size(); ++i) {
            obstacle.insert({pair<int, int>(obstacles[i][0], obstacles[i][1])});
        }

        for (auto i = 0uz; i < commands.size(); ++i) {
            if (commands[i] < 0) {
                if (commands[i] == -2) {
                    direction++;
                } else {
                    direction--;
                }
                direction = (direction + 4) % 4;
            } else {
                auto steps = commands[i];
                switch (direction) {
                    case 0:
                    {
                        while (steps-- > 0 && !obstacle.count(pair<int, int>(x + 1, y))) {
                            x++;
                            max = std::max(max, x * x + y * y);
                        }
                        continue;
                    }
                    case 1:
                    {
                        while (steps-- > 0 && !obstacle.count(pair<int, int>(x, y + 1))) {
                            y++;
                            max = std::max(max, x * x + y * y);
                        }
                        continue;
                    }
                    case 2:
                    {
                        while (steps-- > 0 && !obstacle.count(pair<int, int>(x - 1, y))) {
                            x--;
                            max = std::max(max, x * x + y * y);
                        }
                        continue;
                    }
                    case 3:
                    {
                        while (steps-- > 0 && !obstacle.count(pair<int, int>(x, y - 1))) {
                            y--;
                            max = std::max(max, x * x + y * y);
                        }
                        continue;
                    }
                    default:
                        continue;
                }
            }
        }

        return max;
    }
};