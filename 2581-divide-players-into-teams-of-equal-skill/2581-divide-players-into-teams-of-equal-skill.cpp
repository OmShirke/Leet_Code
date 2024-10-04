class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int mid = n / 2;
        long long chem = 0;

        for (int i = 0; i < mid; i++) {
            if (skill[i] + skill[n - 1] != skill[i + 1] + skill[n - 2]) {
                return -1;
            }
            n--;
        }

        n = skill.size();
        
        for (int i = 0; i < mid; i++) {
            chem += skill[i] * skill[n - 1];
            n--;
        }
        return chem;
    }
};