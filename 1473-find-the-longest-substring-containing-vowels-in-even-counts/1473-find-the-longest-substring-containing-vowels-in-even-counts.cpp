class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mask_map;
        mask_map[0] = -1;
        int mask = 0;
        int max_len = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == 'a')
                mask ^= (1 << 0);
            if (c == 'e')
                mask ^= (1 << 1);
            if (c == 'i')
                mask ^= (1 << 2);
            if (c == 'o')
                mask ^= (1 << 3);
            if (c == 'u')
                mask ^= (1 << 4);

            if (mask_map.count(mask)) {
                max_len = max(max_len, i - mask_map[mask]);
            } else {
                mask_map[mask] = i;
            }
        }
        return max_len;
    }
};