class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int ans=0;
        if(n<2){
            return ans;
        }
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<n;j++){
                if(strs[j][i]<strs[j-1][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};