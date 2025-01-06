class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> ans(n,0);
        int count = 0;
        int moves = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] += moves;
            if(boxes[i]=='1'){
                count++;
            }
            moves += count;
        }
        count = 0;
        moves = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] += moves;
            count += (boxes[i] == '1');
            moves += count;
        }
        return ans;
    }
};