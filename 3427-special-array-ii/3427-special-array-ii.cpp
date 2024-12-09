class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> same_parity(n, 0);
        for (int i = 1; i < n; i++) {
            same_parity[i] = (nums[i] % 2 == nums[i - 1] % 2);
        }

        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + same_parity[i];
        }

        vector<bool> res;
        for (const auto& query : queries) {
            int left = query[0], right = query[1];
            res.push_back(prefix[right] - prefix[left] == 0);
        }
        return res;
    }
};

