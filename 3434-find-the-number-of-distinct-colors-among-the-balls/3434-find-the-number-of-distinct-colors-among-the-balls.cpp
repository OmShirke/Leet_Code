class Solution {
public:
    static vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        const unsigned n=queries.size();
        vector<int> ans(n, 0);
        unordered_map<unsigned, unsigned> mp;
        unordered_map<unsigned, unsigned> color;
        int i=0;
        for (auto& q: queries){
            unsigned x=q[0], c=q[1];
            if (mp.count(x)>0){
                unsigned c0=mp[x];
                if (--color[c0]==0) 
                    color.erase(c0);
            }
            mp[x]=c;
            color[c]++;
            ans[i++]=color.size();
        }
        return ans;
    }
};