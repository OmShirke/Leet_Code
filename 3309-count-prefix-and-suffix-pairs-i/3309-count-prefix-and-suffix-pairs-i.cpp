class Solution {
public:
    bool isPreSuf(string a, string b){
        int n=a.size();
        int m=b.size();
        if(a==b.substr(0,n) && a==b.substr(m-n)){
            return true;
        }
        return false;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(words[i].size()<=words[j].size()){
                    count+=isPreSuf(words[i],words[j]);
                }
            }
        }
        return count;
    }
};