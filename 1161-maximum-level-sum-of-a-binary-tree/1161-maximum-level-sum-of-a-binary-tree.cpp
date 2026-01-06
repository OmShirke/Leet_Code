class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int ans = 1;
        long long maxSum = root->val;

        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            if (sum > maxSum) {
                maxSum = sum;
                ans = level;
            }

            level++;
        }

        return ans;
    }
};
