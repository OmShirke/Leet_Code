class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char one;
        char two;
        bool ind=true;
        bool swaped=false;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i] && !one){
                one=s2[i];
                two=s1[i];
                ind=false;
            }
            else if(s1[i]!=s2[i] && one!=s1[i] && two!=s2[i]){
                return false;
            }
            else if(s1[i]!=s2[i] && one==s1[i] && two==s2[i] && !swaped){
                ind=true;
                one='\0';
                two='\0';
                swaped=true;
            }
        }
        return ind;
    }
};