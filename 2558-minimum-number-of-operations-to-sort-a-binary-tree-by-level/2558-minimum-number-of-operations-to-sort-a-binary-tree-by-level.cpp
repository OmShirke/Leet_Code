class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int res = 0;
        vector<TreeNode*> q{root};
        while (!q.empty()) {
            vector<TreeNode*> q1;
            vector<int> vals, ids(q.size());
            for (auto n : q) {
                vals.push_back(n->val);
                if (n->left != nullptr)
                    q1.push_back(n->left);
                if (n->right != nullptr)
                    q1.push_back(n->right);
            }
            iota(begin(ids), end(ids), 0);
            sort(begin(ids), end(ids),
                 [&](int i, int j) { return vals[i] < vals[j]; });
            for (int i = 0; i < ids.size(); ++i)
                for (; ids[i] != i; ++res)
                    swap(ids[i], ids[ids[i]]);
            swap(q, q1);
        }
        return res;
    }
};