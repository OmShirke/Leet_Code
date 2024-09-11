class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorValue = start ^ goal;

        int count = 0;
        while (xorValue > 0) {
            count += xorValue & 1;
            xorValue >>= 1;
        }

        return count;
    }
};