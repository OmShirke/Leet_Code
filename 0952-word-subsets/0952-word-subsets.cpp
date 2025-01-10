class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        unordered_map<char, int> maxFreq;
        for (string& word : words2) {
            unordered_map<char, int> tempFreq;
            for (char c : word) {
                tempFreq[c]++;
                maxFreq[c] = max(maxFreq[c], tempFreq[c]);
            }
        }

        vector<string> result;
        for (string& word : words1) {
            unordered_map<char, int> wordFreq;
            for (char c : word) {
                wordFreq[c]++;
            }

            bool isUniversal = true;
            for (auto& [ch, count] : maxFreq) {
                if (wordFreq[ch] < count) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                result.push_back(word);
            }
        }
        return result;
    }
};
