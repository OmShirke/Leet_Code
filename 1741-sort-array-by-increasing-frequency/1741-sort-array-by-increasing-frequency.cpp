class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> ans;
        for(int i:nums){
            ans[i]++;
        }
        vector<pair<int,int>> vec(ans.begin(),ans.end());

        sort(vec.begin(),vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return (a.second == b.second) ? a.first > b.first : a.second < b.second;
        });
        
        vector<int> sol;
        for(const auto& i:vec){
            sol.insert(sol.end(),i.second,i.first);
        }
        return sol;
    }
};