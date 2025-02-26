class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int mini=0;
        int maxi=0;
        for(int num:nums){
            sum+=num;
            mini=min(mini,sum);
            maxi=max(maxi,sum);
        }   
        return maxi-mini;
    }
};