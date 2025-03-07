class Solution {
public:
    bool isprime(int num) {
        if (num < 2) return false;
        for (int a = 2; a * a <= num; a++) {
            if (num % a == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        for (int i = left; i <= right; i++) {
            if (isprime(i)) {
                prime.push_back(i);
            }
        }

        if (prime.size() < 2) return {-1, -1};

        int diff = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < prime.size() - 1; i++) {
            int d = prime[i + 1] - prime[i];
            if (d < diff) {
                diff = d;
                a = prime[i];
                b = prime[i + 1];
            }
        }
        return {a, b};
    }
};
