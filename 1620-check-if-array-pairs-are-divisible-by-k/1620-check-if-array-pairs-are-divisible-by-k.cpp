class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;

        for (int num : arr) {
            int rem = (num % k + k) % k;
            remainderCount[rem]++;
        }

        for (auto& [rem, count] : remainderCount) {
            if (rem == 0) {
                if (count % 2 != 0) return false;
            } else {
                if (remainderCount[rem] != remainderCount[k - rem]) return false;
            }
        }
        
        return true;
    }
};
