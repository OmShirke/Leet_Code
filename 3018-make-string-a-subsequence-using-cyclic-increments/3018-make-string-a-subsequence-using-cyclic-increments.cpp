class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int j=0;
        int val1=0;
        int val2=0;
        for(char a:str1){
            val1=a-'a';
            val2=str2[j]-'a';
            if(val1==25 && val2!=val1){
                val1=-1;
            }
            if(val2==val1 || val2==val1+1){
                j++;
            }
            if(j==m){
                return true;
            }
        }
        return false;
    }
};