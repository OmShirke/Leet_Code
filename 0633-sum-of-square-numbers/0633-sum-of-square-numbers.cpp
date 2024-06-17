class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int b = sqrt(c);
        while (a <= b) {
            long long sum = static_cast<long long>(a) * a + static_cast<long long>(b) * b;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                a++;
            } else {
                b--;
            }
        }
        return false;
    }
};

