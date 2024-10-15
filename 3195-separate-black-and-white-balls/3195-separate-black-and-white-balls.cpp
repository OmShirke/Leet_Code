class Solution {
public:
    long long minimumSteps(string s) {

        long long count=0;
        int n=s.size();
        int ind=-1;
        bool zeroFound=false;

        for(int i=n-1;i>=0;i--){
            
            if(s[i]=='0' && ind==-1){
                ind=i;
                zeroFound=true;
            }
            if(s[i]=='1' && zeroFound){
                count+=ind-i;
                ind--;
            }
        }
        return count;
    }
};