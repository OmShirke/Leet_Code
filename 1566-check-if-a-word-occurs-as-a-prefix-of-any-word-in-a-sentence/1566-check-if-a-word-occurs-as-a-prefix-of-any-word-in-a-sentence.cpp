class Solution {
public:
    int isPrefixOfWord(string sentence, string search) {
        int n = search.size();
        string word = "";
        int ans = 0;
        for (int i = 0; i <= sentence.size(); i++) {
            if (i < sentence.size() && sentence[i] != ' ') {
                word += sentence[i];
            } else {
                ans++;
                if (word.size() >= n && word.substr(0, n) == search) {
                    return ans;
                }
                word="";
            }
        }
        return -1;
    }
};