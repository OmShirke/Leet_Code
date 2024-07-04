class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int a:nums){
            count[a]++;
        }
        for(auto& pair:count){
            if(pair.second>2){
                return false;
            }
        }
        return true;
    }
};