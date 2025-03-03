class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int ind = -1;
        queue<int> qlarge, qsmall;
        vector<int> result; 

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == pivot) {
                if (ind == -1) ind = result.size();
                result.push_back(nums[i]);
            } else if (nums[i] > pivot) {
                qlarge.push(nums[i]);
            } else {
                qsmall.push(nums[i]);
            }
        }

        vector<int> finalResult;
        
        while (!qsmall.empty()) {
            finalResult.push_back(qsmall.front());
            qsmall.pop();
        }
        
        finalResult.insert(finalResult.end(), result.begin(), result.end());

        while (!qlarge.empty()) {
            finalResult.push_back(qlarge.front());
            qlarge.pop();
        }

        return finalResult;
    }
};
