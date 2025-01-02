class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> binary(n, 0);
        for (int i = 0; i < n; ++i) {
            if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
                binary[i] = 1;
            }
        }
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + binary[i];
        }
        vector<int> ans;
        for (const auto& q : queries) {
            ans.push_back(prefixSum[q[1] + 1] - prefixSum[q[0]]);
        }
        return ans;
    }
};
