class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        int left = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            mp[c]++;

            while (mp[c] > 1) {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};