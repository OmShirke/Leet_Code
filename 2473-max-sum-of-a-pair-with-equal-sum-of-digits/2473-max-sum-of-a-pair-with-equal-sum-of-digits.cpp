class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = -1;
        for (int num : nums) {
            int sum = 0, temp = num;
            while (temp > 0) {  
                sum += temp % 10;
                temp /= 10;
            }
            if (mp.find(sum) != mp.end()) {
                res = max(res, num + mp[sum]);
                mp[sum] = max(mp[sum], num);  
            } else {
                mp[sum] = num;
            }
        }
        return res;
    }
};
