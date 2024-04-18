class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int ans;
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());
        for( int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
               count++;       
               if(count>n/2){
               ans=nums[i];
               break;
               }
            }
            else{
            count=1;
            }
        }
        return ans;
    }
};