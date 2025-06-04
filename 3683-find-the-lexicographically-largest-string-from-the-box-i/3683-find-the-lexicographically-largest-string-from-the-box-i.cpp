class Solution {
public:
    string answerString(string word, int numFri) {
        int n=word.size();
        if(numFri==1){
            return word;
        }
        int maxlen=n-numFri+1;
        string ans="";
        for(int i=0;i<n;i++){
            string temp=word.substr(i,maxlen);
            ans=max(ans,temp);
        }
        return ans;
    }
};