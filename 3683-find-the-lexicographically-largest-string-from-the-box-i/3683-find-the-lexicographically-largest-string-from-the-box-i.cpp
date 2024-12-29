class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1)
            return word;

        string ans="";
        int len=n-numFriends+1;
        for(int i=0;i<n;i++){
            ans=max(ans,word.substr(i,len));
        }
        return ans;
    }
};
