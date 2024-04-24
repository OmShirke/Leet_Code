class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1 && nums[0]!=0) return nums[0]-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]+1!=nums[i+1]){
                return nums[i]+1;
            }
        }
        if(nums[0]==0){
        return nums[n-1]+1;
        }
        return nums[0]-1;
    }
};