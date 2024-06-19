class Solution {
public:
    int minDays(vector<int>& A, int m, int k) {
        int n = A.size();
        if ((long long)m * k > n)
            return -1;

        int left = *min_element(A.begin(), A.end());
        int right = *max_element(A.begin(), A.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            int flow = 0, bouq = 0;
            for (int j = 0; j < n; ++j) {
                if (A[j] > mid) {
                    flow = 0;
                } else if (++flow >= k) {
                    bouq++;
                    flow = 0;
                }
            }
            if (bouq < m) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
