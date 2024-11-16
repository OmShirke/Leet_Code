class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res(n - k + 1, -1);

        if(n<2){
            res[0]=nums[0];
        }


        for (int i = 0; i <= n - k; i++) {
            bool ispower = true;

            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] + 1 == nums[j + 1]) {
                    continue;
                } else {
                    ispower = false;
                    break;
                }
            }
            if (ispower) {
                res[i] = nums[i+k-1];
            }
        }
        return res;
    }
};