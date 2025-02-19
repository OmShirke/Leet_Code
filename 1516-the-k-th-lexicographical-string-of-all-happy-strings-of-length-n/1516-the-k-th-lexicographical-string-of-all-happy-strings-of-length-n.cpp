class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * pow(2, n - 1);
        if (k > total) return ""; 

        string ans = "";
        int a = total / 3;
        int b = (k - 1) / a; 
        int c = (k - 1) % a;

        if (b == 0) ans.push_back('a');
        else if (b == 1) ans.push_back('b');
        else ans.push_back('c');

        string choices = "abc";
        for (int i = n - 1; i > 0; --i) {
            a /= 2;
            int nextIndex = c / a;
            c %= a;

            for (char ch : choices) {
                if (ch != ans.back()) {
                    if (nextIndex == 0) {
                        ans.push_back(ch);
                        break;
                    }
                    nextIndex--;
                }
            }
        }

        return ans;
    }
};
