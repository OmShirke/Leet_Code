class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    int n= nums.size();
    vector<int> ans(n,INT_MIN);
        for(int i=0;i<k;i++){
            q.push({nums[i],i});
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>q.top().first){
                q.pop();
                q.push({nums[i],i});
            }
        }
        for(int i=0;i<k;i++){
            ans[q.top().second]=q.top().first;
            q.pop();
        }
        ans.erase(remove(ans.begin(), ans.end(), INT_MIN), ans.end());
        return ans;
    }
    
};