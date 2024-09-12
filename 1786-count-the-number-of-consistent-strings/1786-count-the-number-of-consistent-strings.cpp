class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        sort(allowed.begin(),allowed.end());
        unordered_set<char> mp(allowed.begin(),allowed.end());
        int count=0;

        for(const string& word : words){
            bool idk=true;
            for(char c:word){
                if(mp.find(c)==mp.end()){
                    idk=false;
                    break;
                }
            }
            
            if(idk){
                count++;
            }
        }
        return count;
    }
};