class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int ans=0;
        while(i<n){
            if(nums[i]<0){
                ans=i+1;
            }else if(nums[i]>0){
                ans=max(ans,n-i);
                break;
            }
            i++;
        }
        return ans;
    }
};