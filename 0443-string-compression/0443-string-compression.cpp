class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int count = 1;
        int ptr = 0;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && chars[i] == chars[i + 1]) {
                count++;
            } else {
                chars[ptr++] = chars[i];

                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[ptr++] = c;
                    }
                    ans += countStr.size() + 1;
                    count = 1;
                } else {
                    ans++;
                }
            }
        }
        chars.resize(ptr);
        return ans;
    }
};

