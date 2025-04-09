class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int ,int> mp;
        sort(nums.begin(),nums.end());
        for(int a:nums){
            mp[a]++;
        }
        if(k<nums[0]){
            return mp.size();
        }
        else if(k==nums[0]){
            return mp.size()-1;
        }
        return -1;
    }
};