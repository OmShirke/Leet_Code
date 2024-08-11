class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;

        for (int i = 0; i < s.size(); i++) {
            char sc = s[i];
            char tc = t[i];
            if (smap.find(sc) != smap.end()) {
                if (smap[sc] != tc) {
                    return false;
                }
            } else {
                smap[sc] = tc;
            }
            if (tmap.find(tc) != tmap.end()) {
                if (tmap[tc] != sc) {
                    return false;
                }
            } else {
                tmap[tc] = sc;
            }
        }

        return true;
    }
};

