class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int n = pref.size();
        for (int i = 0; i < words.size(); i++) {
            if (pref == words[i].substr(0, n)) {
                count++;
            }
        }
        return count;
    }
};