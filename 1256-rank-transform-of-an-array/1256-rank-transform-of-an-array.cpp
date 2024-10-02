class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> vec(arr);
        sort(vec.begin(), vec.end());
        unordered_map<int, int> mp;
        for (int& a : vec) {
            mp.emplace(a, mp.size() + 1);
        }
        for (int i = 0; i < vec.size(); i++) {
            vec[i] = mp[arr[i]];
        }

        return vec;
    }
};