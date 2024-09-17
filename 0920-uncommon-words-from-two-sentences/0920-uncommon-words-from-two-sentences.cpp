class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream ss(s1+" "+s2);
        unordered_map<string,int> mp;
        while(ss >> s1) mp[s1]++;
        vector<string> ans;
        for(auto a:mp){
            if(a.second==1){
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};