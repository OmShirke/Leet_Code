class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> tar;
        map<int,int> a;
        for(const auto b:target){
            tar[b]++;
        }
        for(const auto c:arr){
            a[c]++;
        }
        return tar==a;
    }
};