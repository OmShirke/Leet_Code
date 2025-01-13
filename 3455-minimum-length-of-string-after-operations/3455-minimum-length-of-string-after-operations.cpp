class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        int ans=s.size();
        for(const auto& [key,value]:mp){
            if(value>2 && value%2==1){
                ans=ans-value+1;
            }
            else if(value>2){
                ans=ans-value+2;
            }
        }
        return ans;
    }
};