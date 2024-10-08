class Solution {
public:
    int minSwaps(string s) {
        int unbalanced = 0;
        int balance = 0;    
        
        for (char c : s) {
            if (c == '[') {
                balance++; 
            } else {
                if (balance > 0) {
                    balance--; 
                } else {
                    unbalanced++; 
                }
            }
        }
        
        return (unbalanced + 1) / 2;
    }
};

