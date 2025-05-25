class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp, visited;
        for (auto& word : words) {
            mp[word]++;
        }

        int temp = 0;
        int same = 0;
        bool isodd = false;
        int ans = 0;
        for (auto& ch : mp) {
            int value = ch.second;
            string curr = ch.first;
            string rev = curr;
            if (visited.find(curr) == visited.end() &&
                visited.find(rev) == visited.end()) {
                reverse(rev.begin(), rev.end());
                if (curr[0] == curr[1]) {
                    if (value % 2 == 0) {
                        temp += value;
                    } else if (value % 2 == 1) {
                        isodd = true;
                        temp += (value - 1);
                    }
                } else if (mp.find(rev) != mp.end()) {
                    int a = value;
                    int b = mp[rev];
                    ans += min(a, b);
                    visited[curr]++;
                    visited[rev]++;
                }
            }
        }
        ans = ans * 4;
        temp = temp * 2;
        int output = temp + ans;
        if (isodd)
            output += 2;
        return output;
    }
};