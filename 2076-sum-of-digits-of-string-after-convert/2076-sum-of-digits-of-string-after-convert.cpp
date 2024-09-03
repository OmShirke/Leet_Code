class Solution {
public:
    int getLucky(string s, int k) {
        string str;
        int sum = 0;
        
        for (char ch : s) {
            int val = ch - 'a' + 1;
            str += to_string(val);
        }
        
        for (char digit : str) {
            sum += digit - '0';
        }
        
        for (int i = 1; i < k; ++i) {
            int new_sum = 0;
            while (sum > 0) {
                new_sum += sum % 10;
                sum /= 10;
            }
            sum = new_sum;
        }
        
        return sum;
    }
};
