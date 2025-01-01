class Solution {
public:
    int maxScore(string s) {
        unordered_map<char,int> left;
        unordered_map<char,int> right;
        int ans=0;

        for(char c:s){
            right[c]++;
        }

        for(int i=0;i<s.size()-1;i++){
            int temp=0;
            left[s[i]]++;
            right[s[i]]--;
            temp+=left['0'];
            temp+=right['1'];
            if(temp==s.size()){
                return temp;
            }
            ans=max(ans,temp);
        }

        return ans;

    }
};