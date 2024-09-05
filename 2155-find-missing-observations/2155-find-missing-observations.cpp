class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size = rolls.size();
        int nume = 0;
        int calc = (size + n) * mean;

        for (int i = 0; i < size; i++) {
            nume += rolls[i];
        }
        calc -= nume;

        if (calc < n || calc > 6 * n) {
            return {};
        }
        
        vector<int> ans(n, calc / n);
        int remainder = calc % n;

        for (int i = 0; i < remainder; i++) {
            ans[i]++;
        }
        return ans;
    }
};