class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int a : arr) {
            mp[a]++;
        }
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i] * 2;
            auto it = mp.find(num);
            if (num == 0 && it->second < 2) {
                continue;
            }
            if (it != mp.end()) {
                return true;
            }
        }
        return false;
    }
};