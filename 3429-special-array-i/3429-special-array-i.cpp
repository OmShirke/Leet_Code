class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool ans=true;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]%2==nums[i]%2){
                return false;
            }
        }
        return true;
    }
};