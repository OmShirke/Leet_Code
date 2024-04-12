class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        int ans=0;
        bool b=false;
       for(int i=n;i>=0;i--){
        if(s[i]!=' '){
            ans++;
            b=true;
        }
        else if(b==true){    
            break;
        }
       }
       return ans;
    }
};