class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n=nums1.size();
        int m=nums2.size();
        unordered_map<int,int> mp;
        for(const auto& num:nums1){
            mp[num[0]]=num[1];
        }
        for(const auto& num:nums2){
            mp[num[0]]+=num[1];
        }
        int start=min(nums1[0][0],nums2[0][0]);
        int end=max(nums1[n-1][0],nums2[m-1][0]);

        for(int i=start;i<=end;i++){
            if(mp.find(i)!=mp.end()){
                ans.push_back({i,mp[i]});
            }
        }
        return ans;
    }
};