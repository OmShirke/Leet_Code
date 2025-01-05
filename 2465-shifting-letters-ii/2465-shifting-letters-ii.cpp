class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> temp(n + 1, 0); 
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            temp[start] += (direction == 1) ? 1 : -1;
            temp[end + 1] += (direction == 1) ? -1 : 1;
        }

        int shiftSum = 0;
        for (int i = 0; i < n; i++) {
            shiftSum += temp[i];
            int shift = (shiftSum % 26 + 26) % 26;
            s[i] = (s[i] - 'a' + shift) % 26 + 'a';
        }

        return s;
    }
};
