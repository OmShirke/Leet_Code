class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> ans(n);
        unordered_map<int, int> amp, bmp;

        for (int i = 0; i < n; i++) {
            int count = 0;
            if (a[i] == b[i]) count++;
            if (bmp.find(a[i]) != bmp.end()) count++;
            if (amp.find(b[i]) != amp.end()) count++;

            ans[i] = (i == 0) ? count : ans[i - 1] + count;

            amp[a[i]]++;
            bmp[b[i]]++;
        }

        return ans;
    }
};

