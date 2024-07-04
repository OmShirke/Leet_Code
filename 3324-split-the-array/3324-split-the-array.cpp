class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n%2!=0){
            return false;
        }
        for(int i=0;i<n-2;i++){
            if(nums[i]==nums[i+1] && nums[i]==nums[i+2]){
                return false;
            }
        }
        return true;
    }
};