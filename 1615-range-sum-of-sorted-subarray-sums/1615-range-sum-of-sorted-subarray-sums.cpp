class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans=0;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        for(int i=left-1;i<right;i++){
            ans+=arr[i];
            ans%=1000000007;
        }
        return ans;
    }
};