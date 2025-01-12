class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2==1){
            return false;
        }

        int bal=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(' || locked[i]=='0'){
                bal++;
            }
            else{
                bal--;
            }

            if(bal<0){
                return false;
            }
        }

        bal=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || locked[i]=='0'){
                bal++;
            }
            else{
                bal--;
            }

            if(bal<0){
                return false;
            }
        }
        return true;
    }
};