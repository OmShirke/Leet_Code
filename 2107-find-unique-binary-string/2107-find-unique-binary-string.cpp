class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_set<string> mp(nums.begin(), nums.end());

        int total = 1 << n;
        int i = 0;
        string res(n, '0');

        while (i < total) {
            if (mp.find(res) == mp.end()) {
                return res;
            }

            int num = stoi(res, nullptr, 2);
            num++;
            res = bitset<16>(num).to_string().substr(16 - n);

            i++;
        }
        return res;
    }
};
