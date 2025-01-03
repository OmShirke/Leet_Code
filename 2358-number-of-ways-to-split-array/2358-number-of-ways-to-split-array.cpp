class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count=0;
        long long rsum=0;
        for(int num:nums){
            rsum+=num;
        }

        long long lsum=0;
        for(int i=0;i<nums.size()-1;i++){
            rsum-=nums[i];
            lsum+=nums[i];
            if(lsum>=rsum){
                count++;
            }
        }
        return count;
    }
};