class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int num:arr){
            mp[num]++;
        }
        int ans=-1;
        for(auto [key,value]:mp){
            if(key==value){
                ans=max(ans,key);
            }
        }
        return ans;
    }
};