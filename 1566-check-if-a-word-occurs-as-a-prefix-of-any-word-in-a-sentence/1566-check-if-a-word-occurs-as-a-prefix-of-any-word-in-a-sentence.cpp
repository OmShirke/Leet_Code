class Solution {
public:
    int isPrefixOfWord(string sentence, string search) {
        int n = search.size();
        string word = "";
        int ans = 0;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] != ' ') {
                word += sentence[i];
            } else if (word.size() >= n) {
                ans++;
                for (int j = 0; j < n; j++) {
                    if (word[j] != search[j]) {
                        word = "";
                        break;
                    }
                    if (j == n - 1) {
                        return ans;
                    }
                }
            } else {
                ans++;
                word = "";
            }
        }
        ans++;
        for (int j = 0; j < n; j++) {
            if (word[j] != search[j]) {
                break;
            }
            if (j == n - 1) {
                return ans;
            }
        }

        return -1;
    }
};