class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int,int> mp;
        for(const auto& num:nums1){
            mp[num[0]]=num[1];
        }
        for(const auto& num:nums2){
            mp[num[0]]+=num[1];
        }
        for (const auto& [key, value] : mp) {
            ans.push_back({key, value});
        }
        return ans;
    }
};