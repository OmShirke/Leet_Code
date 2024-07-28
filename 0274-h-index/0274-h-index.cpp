class Solution {
public:
    int hIndex(vector<int>& ci) {
        int n=ci.size();
        int count=0;
        sort(ci.begin(),ci.end());
        for(int i=0;i<n;i++){
            if(ci[i]>=n-i){
               count=max(count,n-i);
            }
        }
        return count;
    }
};