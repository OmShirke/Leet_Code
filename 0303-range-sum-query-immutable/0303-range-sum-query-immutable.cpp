class NumArray {
public:
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        long long ans = 0;
        
        for(int i = left; i <= right; i++) {
            ans += nums[i];
        }

        return ans;
    }
};