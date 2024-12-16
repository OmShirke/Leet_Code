class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        priority_queue<int, vector<int>, greater<int>> heap(nums.begin(), nums.end());
        int n=nums.size();
        int i=0;
        while(i<n && k>0){
            if(nums[i]==heap.top()){
                nums[i]*=multi;
                heap.pop();
                heap.push(nums[i]);
                i=0;
                k--;
                continue;
            }
            i++;
        }
        return nums;
    }
};