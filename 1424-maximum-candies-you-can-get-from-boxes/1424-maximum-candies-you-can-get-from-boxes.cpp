class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;
        int n = status.size();
        queue<int> q;
        vector<int> vis(n, 0);    
        vector<int> boxAvailable(n, 0); 
        vector<int> haveKey(n, 0);
        for (int box : initialBoxes) {
            boxAvailable[box] = 1;
        }

        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < n; ++i) {
                if (boxAvailable[i] && !vis[i] && (status[i] == 1 || haveKey[i])) {
                    vis[i] = 1;
                    ans += candies[i];

                    for (int k : keys[i]) {
                        if (!haveKey[k]) {
                            haveKey[k] = 1;
                            changed = true;
                        }
                    }

                    for (int b : containedBoxes[i]) {
                        if (!boxAvailable[b]) {
                            boxAvailable[b] = 1;
                            changed = true;
                        }
                    }
                    changed = true;
                }
            }
        }

        return ans;
    }
};
