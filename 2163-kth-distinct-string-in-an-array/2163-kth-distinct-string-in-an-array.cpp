class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (const auto& num : arr) {
            mp[num]++;
        }
        int count = 0;
        for (const auto& str : arr) {
            if (mp[str] == 1) {
                count++;
                if (count == k) {
                    return str;
                }
            }
        }
        return "";
    }
};