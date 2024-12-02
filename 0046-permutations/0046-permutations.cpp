class Solution {
public:
    void permutation(vector<int>& nums, int st, vector<vector<int>>& ans) {
        if (st == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = st; i < nums.size(); i++) {
            swap(nums[i], nums[st]);
            permutation(nums, st + 1, ans);
            swap(nums[i], nums[st]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(nums, 0, ans);
        return ans;
    }
};