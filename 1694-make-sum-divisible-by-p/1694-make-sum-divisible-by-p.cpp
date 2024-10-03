class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long remainder = total % p;
        
        if (remainder == 0) return 0;
        
        unordered_map<long long, int> prefixMod;
        prefixMod[0] = -1; 
        
        long long prefixSum = 0;
        int minLen = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            
            long long target = (prefixSum - remainder + p) % p;
            
            if (prefixMod.find(target) != prefixMod.end()) {
                minLen = min(minLen, i - prefixMod[target]);
            }
            
            prefixMod[prefixSum] = i;
        }
        
        return minLen == nums.size() ? -1 : minLen;
    }
};
