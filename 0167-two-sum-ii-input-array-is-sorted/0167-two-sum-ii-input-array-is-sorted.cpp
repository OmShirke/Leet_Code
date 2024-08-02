class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int lt=0;
        int rt=n-1;
        while(lt<rt){
            if(nums[lt]+nums[rt]==target){
                return {lt+1,rt+1};
            }
            else if(nums[lt]+nums[rt]>target){
                rt--;
            }
            else{
                lt++;
            }
        }
        return {};
    }
};