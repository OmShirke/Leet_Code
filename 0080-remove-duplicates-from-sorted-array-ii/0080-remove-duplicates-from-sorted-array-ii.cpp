class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=n;
        for(int i=0;i<n-2;i++){
            if(nums[i]==nums[i+2]){
                nums[i]=INT_MAX;
                k--;
            }
        }
        sort(nums.begin(),nums.end());
        return k;
    }
};