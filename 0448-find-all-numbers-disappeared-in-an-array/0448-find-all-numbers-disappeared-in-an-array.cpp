class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, bool> present;
        for (int num : nums) {
            present[num] = true;
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (!present[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
