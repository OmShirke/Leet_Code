class Solution {
public:
    bool rotateString(string s, string goal) {
        bool ans=false;
        int n=s.size();
        int count=0;
        int i=0;
        while(count<=n){
            if(s==goal){
                ans=true;
                break;
            }
            else{
                s.push_back(s[i]);
                s.erase(i,1);
                i--;
            }
            i++;
            count++;
        }
        return ans;
    }
};