class Solution {
public:
    string invert(const string& ans) {
        string inverted = ans;
        for (char& c : inverted) {
            c = (c == '1') ? '0' : '1';
        }
        return inverted;
    }

    char findKthBit(int n, int k) {
        string ans = "0";  
        
        for (int i = 1; i < n; ++i) {
            string after = invert(ans);
            reverse(after.begin(), after.end()); 
            ans = ans + "1" + after; 
        }

        return ans[k - 1]; 
    }
};