class Solution {
public:
    int numTilePossibilities(string tiles) {
        int counts[26] {}; 
        for (const auto &c :  tiles) {
            counts[c - 'A']++;
        }
        int result = 0;
        rec(counts, result);
        return result;
    }

    void rec(int counts[26], int &result) {
        for(int i = 0; i < 26; ++i) {
            if (counts[i]){
                counts[i]--;
                result++;
                rec(counts, result);
                counts[i]++;
            }
        }
    }
};