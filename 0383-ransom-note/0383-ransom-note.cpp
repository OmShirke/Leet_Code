class Solution {
public:
    bool canConstruct(string rnote, string magz) {
        map<char, int> rn;
        map<char,int> mag;
        for(char c:rnote){
            rn[c]++;
        }
        for(char c:magz){
            mag[c]++;
        }
        for (auto& pair : rn) {
            char c = pair.first;
            int count = pair.second;
            if (mag[c] < count) {
                return false;
            }
        }
        return true;;
    }
};