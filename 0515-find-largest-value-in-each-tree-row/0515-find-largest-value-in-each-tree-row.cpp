class Solution {
    vector<int> solution;
public:
    void helper(TreeNode* node, int cl) {
        if (node == NULL) {
            return;
        }
        if (solution.size() < cl + 1) {
            solution.push_back(node->val);
        } else {
            if (solution[cl] < node->val) {
                solution[cl] = node->val;
            }
        }
        helper(node->left, cl+1);
        helper(node->right, cl+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) {
            return solution;
        }
        
        helper(root, 0);
        return solution;
    }
};