class Solution {
public:
    int maximumLength(string st) {
        map<pair<char, int>, int> mp;
        int count = 0;

        for (int i = 0; i < st.size(); i++) {
            count = 1;
            mp[{st[i], count}]++;

            for (int j = i; j < st.length(); j++) {
                if (st[j] == st[j + 1]) {
                    count++;
                    mp[{st[i], count}]++;
                } else {
                    break;
                }
            }
        }

        int ans1 = 0;

        for (auto x : mp) {
            if (x.second >= 3) {
                ans1 = max(x.first.second, ans1);
            }
        }

        return (ans1 == 0) ? -1 : ans1;
    }
};
