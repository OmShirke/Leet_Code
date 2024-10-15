class Solution {
public:
    long long minimumSteps(string s) {

        long long count=0;
        int n=s.size();
        int ind=INT_MAX;
        bool idk=false;

        for(int i=n-1;i>=0;i--){
            
            if(s[i]=='0' && ind==INT_MAX){
                ind=i;
                idk=true;
            }
            if(s[i]=='1' && idk){
                count+=ind-i;
                ind--;
            }
        }
        return count;
    }
};