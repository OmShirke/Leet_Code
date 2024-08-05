class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n= nums.size();
        vector<long long> ans;
        long long sum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            long long a=nums[i]+maxi;
            sum+=a;
            ans.push_back(sum);
        }
        return ans;
    }
};