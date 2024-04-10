class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans="";
        int n=strs.size();
        string first=strs[0];
        string last=strs[n-1];
        for(int i=0;i<min(last.length(),first.length());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            else{
                ans +=first[i];
            }
        }
        return ans;   
    };
};