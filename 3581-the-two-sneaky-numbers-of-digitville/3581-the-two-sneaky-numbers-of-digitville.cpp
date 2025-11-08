class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int num:nums){
            mp[num]++;
            if(mp[num]>1){
                ans.push_back(num);
            }
            if(ans.size()==2){
                return ans;
            }
        }
        return ans;
    }
};