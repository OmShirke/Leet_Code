class Solution {
public:
    string clearDigits(string s) {
        int i = 0;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                s.erase(s.begin() + i);
                if (i > 0) {
                    s.erase(s.begin() + (i - 1));
                    i--;
                }
            } else {
                i++;
            }
        }
        return s;
    }
};
