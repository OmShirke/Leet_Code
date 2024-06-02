class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int a=n-1;
        int i=0;
        if(n<2){};
        while(a>i){
            swap(s[i],s[a]);
            a--;
            i++;
        }
    }
};