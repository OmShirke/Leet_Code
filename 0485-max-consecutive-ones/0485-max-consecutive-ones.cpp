class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1){
                ans=0;
            }
            else{
                ans++;
            }
            if(res<ans){
                res=ans;
            }
        }
        return res;
    }
};