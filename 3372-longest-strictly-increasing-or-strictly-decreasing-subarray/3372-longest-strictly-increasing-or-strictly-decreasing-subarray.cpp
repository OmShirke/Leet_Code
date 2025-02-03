class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int count=1;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                count++;
            }
            else{
                ans=max(count,ans);
                count=1;
            }
        }
        for(int i=n-1;i>0;i--){
            if(nums[i]<nums[i-1]){
                count++;
            }
            else{
                ans=max(count,ans);
                count=1;
            }
        }
        ans=max(count,ans);
        return ans;
    }
};