class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        unordered_set<int> numset(nums.begin(), nums.end());
        int max_streak = 0;
        
        for (auto num : numset) {
            if(numset.find(num - 1) == numset.end()) {
                int currnum = num;
                int currstreak = 1;
                
                while(numset.find(currnum + 1) != numset.end()) {
                    currnum++;
                    currstreak++;
                }
                
                max_streak = max(max_streak, currstreak);
            }
        }
        
        return max_streak;
    }
};
