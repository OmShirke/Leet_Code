class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        auto it = remove(nums.begin(), nums.end(), 0);
        int zeroCount = nums.end() - it;
        nums.erase(it, nums.end());
        nums.insert(nums.end(), zeroCount, 0);
        return nums;
    }
};
