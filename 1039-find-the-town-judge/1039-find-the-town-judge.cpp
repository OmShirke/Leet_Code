class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> scr(n + 1, 0);
        if (n == 1 && trust.empty()) {
            return 1;
        }
        for (const auto& t : trust) {
            int a = t[0];
            int b = t[1];
            scr[a]--;
            scr[b]++;
        }
        for (int i = 0; i <= n; i++) {
            if (scr[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }    
};