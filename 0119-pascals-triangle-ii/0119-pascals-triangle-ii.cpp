class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> nums(rowIndex + 1, 0);
        nums[0] = 1;

        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                nums[j] = nums[j] + nums[j - 1];
            }
        }
        return nums;
    }
};
