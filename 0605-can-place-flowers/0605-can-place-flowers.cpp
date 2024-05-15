class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        int m = bed.size();
        int res = 0;
        if (m == 1) {
            if (bed[0] == 0) {
                res++;
            }
            return res >= n;
        }
        if (bed[0] == 0 && bed[1] == 0) {
            bed[0] = 1;
            res++;
        }
        if (bed[m-1] == 0 && bed[m-2] == 0) {
            bed[m-1] = 1;
            res++;
        }
        for (int i = 1; i < m - 1; i++) {
            if (bed[i] == 0 && bed[i - 1] == 0 && bed[i + 1] == 0) {
                bed[i] = 1;
                res++;
            }
        }

        return res >= n;
    }
};
