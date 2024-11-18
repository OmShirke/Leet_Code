class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int j = i+1;
                int count = 0;
                int sum = 0;
                while (count < k) {
                    if (j == n) {
                        j = 0;
                    }
                    sum += code[j];
                    count++;
                    j++;
                }
                res[i] = sum;
            }
        } 
        else if (k < 0) {
            for (int i = n-1; i >=0; i--) {
                int j = i-1;
                int count = 0;
                int sum = 0;
                while (count > k) {
                    if (j == -1) {
                        j = n-1;
                    }
                    sum += code[j];
                    count--;
                    j--;
                }
                res[i] = sum;
            }
        }
        else{
            return res;
        }
        return res;
    }
};