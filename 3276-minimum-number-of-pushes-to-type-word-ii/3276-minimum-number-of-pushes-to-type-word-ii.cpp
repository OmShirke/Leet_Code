
class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int cal = 1;
        int var = 8;
        unordered_map<char, int> mp;
        
        for (char c : word) {
            mp[c]++;
        }

        vector<pair<char, int>> freqVec(mp.begin(), mp.end());
        sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });

        int i = 0;
        for (const auto& entry : freqVec) {
            if (i >= var) {
                cal++;
                var +=8;
            }
            ans += entry.second * cal;
            i++;
        }
        
        return ans;
    }
};