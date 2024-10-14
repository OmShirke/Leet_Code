class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int> maxHeap(nums.begin(), nums.end());

        long long ans = 0;

        while (k--) {
            int top = maxHeap.top();
            maxHeap.pop();
            ans += top;
            int after = ceil(top / 3.0);
            maxHeap.push(after);
        }

        return ans;
    }
};