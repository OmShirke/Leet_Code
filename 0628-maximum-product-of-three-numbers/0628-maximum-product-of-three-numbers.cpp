class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mul=1;
        int n = nums.size()-1;   
        sort(nums.begin(), nums.end());
        int res =nums[0]*nums[1]*nums[n];
        for (int i = 0; i < 3; i++) {
            mul *= nums[n];
            n--;
        }
        return max(mul,res);
    }
};