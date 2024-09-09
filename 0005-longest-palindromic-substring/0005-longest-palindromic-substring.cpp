class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int n = s.size();
        int start = 0, max = 1;

        for (int i = 0; i < n; ++i) {
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int curr = right - left + 1;
                if (curr > max) {
                    start = left;
                    max = curr;
                }
                --left;
                ++right;
            }

            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int curr = right - left + 1;
                if (curr > max) {
                    start = left;
                    max = curr;
                }
                --left;
                ++right;
            }
        }

        return s.substr(start, max);
    }
};
