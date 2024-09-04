class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, direction = 0, maxDist = 0;

        unordered_set<string> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        for (int command : commands) {
            if (command == -1) {
                direction = (direction + 1) % 4;
            } else if (command == -2) {
                direction = (direction + 3) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int nextX = x + directions[direction].first;
                    int nextY = y + directions[direction].second;
                    if (obstacleSet.find(to_string(nextX) + "," +
                                         to_string(nextY)) ==
                        obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        maxDist = max(maxDist, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }
        return maxDist;
    }
};
