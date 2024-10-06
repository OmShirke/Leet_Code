class Solution {
public:
    bool areSentencesSimilar(string sen1, string sen2) {
        istringstream str1(sen1);
        istringstream str2(sen2);  

        vector<string> word1;
        vector<string> word2;
        string word;
        
        while (str1 >> word) {
            word1.push_back(word);
        }
        
        while (str2 >> word) {
            word2.push_back(word);
        }
        
        int n = word1.size();
        int m = word2.size();
        
        if (sen1 == sen2) return true;
        
        int left = 0, right = 0;
        
        while (left < n && left < m && word1[left] == word2[left]) {
            left++;
        }
        
        while (right < n - left && right < m - left && word1[n - right - 1] == word2[m - right - 1]) {
            right++;
        }
        
        return left + right == min(n, m);
    }
};
