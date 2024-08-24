class Solution {
public:
    string nearestPalindromic(string n) {
        int m = n.size();
        vector<string> candidates;
        
        if (n == "1") return "0";

        candidates.push_back(string(m - 1, '9'));
        candidates.push_back("1" + string(m - 1, '0') + "1");

        string palin = n;
        for (int i = 0; i < m / 2; ++i) {
            palin[m - 1 - i] = palin[i];
        }
        candidates.push_back(palin);

        string smaller = n.substr(0, (m + 1) / 2);
        smaller = to_string(stoll(smaller) - 1);
        string smaller_palin = smaller + string(smaller.rbegin() + (m % 2), smaller.rend());
        candidates.push_back(smaller_palin);

        string larger = n.substr(0, (m + 1) / 2);
        larger = to_string(stoll(larger) + 1);
        string larger_palin = larger + string(larger.rbegin() + (m % 2), larger.rend());
        candidates.push_back(larger_palin);

        string result = "";
        long long num = stoll(n), min_diff = LLONG_MAX;
        for (auto &candidate : candidates) {
            if (candidate == n || candidate[0] == '0') continue;
            try {
                long long cand_num = stoll(candidate);
                long long diff = abs(cand_num - num);
                if (diff < min_diff || (diff == min_diff && cand_num < stoll(result))) {
                    min_diff = diff;
                    result = candidate;
                }
            } catch (const std::invalid_argument& e) {
                continue;
            }
        }

        return result;
    }
};


