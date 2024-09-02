class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int ind = 0;
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += chalk[i];
        }
        k %= total;
        for (int i = 0; i < n; i++) {
            if (chalk[i] > k) {
                ind = i;
                break;
            }
            k -= chalk[i];
        }
        return ind;
    }
};