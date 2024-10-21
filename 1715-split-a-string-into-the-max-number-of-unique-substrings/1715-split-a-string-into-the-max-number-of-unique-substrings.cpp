class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> uniqueSubstrings;
        return backtrack(s, 0, uniqueSubstrings);
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& uniqueSubstrings) {
        if (start == s.size()) return 0;
        
        int maxSplit = 0;
        string currentSubstr;
        
        for (int i = start; i < s.size(); ++i) {
            currentSubstr = s.substr(start, i - start + 1);
            
            if (uniqueSubstrings.find(currentSubstr) == uniqueSubstrings.end()) {
                uniqueSubstrings.insert(currentSubstr);
                int splits = 1 + backtrack(s, i + 1, uniqueSubstrings);
                maxSplit = max(maxSplit, splits);
                uniqueSubstrings.erase(currentSubstr);
            }
        }
        
        return maxSplit;
    }
};
