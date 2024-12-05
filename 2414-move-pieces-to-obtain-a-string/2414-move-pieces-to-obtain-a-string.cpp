class Solution {
public:
    bool canChange(string a, string b) {
        int n=a.size();
        int i=0;
        int j=0;
        while(i<n || j<n){
            while(a[i]=='_' && i<n) i++;
            while(b[j]=='_' && j<n) j++;

            if(i==n && j==n){ return true;}

            if(i==n || j==n){ return false;}

            if(a[i]!=b[j]) return false;

            if(a[i]=='L' && i<j) return false;
            if(a[i]=='R' && i>j) return false;

            i++;
            j++;
        }
        return true;
    }
};