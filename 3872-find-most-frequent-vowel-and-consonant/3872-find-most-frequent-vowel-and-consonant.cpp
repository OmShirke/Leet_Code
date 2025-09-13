class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;
        int a=0;
        int b=0;
        for(char c:s){
            mp[c]++;
        }
        for(auto [key,value]:mp){
            if(key=='a' || key=='e' || key=='i' || key=='o' || key=='u'){
               a=max(a,value);
            }
            else{
                b=max(b,value);
            }
        }
        return a+b;
    }
};