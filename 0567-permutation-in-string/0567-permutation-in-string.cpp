class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        if (n > m) return false;  
        
        sort(s1.begin(), s1.end()); 
        
        for (int i = 0; i <= m - n; i++) {  
            string s3 = s2.substr(i, n); 
            sort(s3.begin(), s3.end());   
            if (s3 == s1) { 
                return true;
            }
        }
        return false;
    }
};
