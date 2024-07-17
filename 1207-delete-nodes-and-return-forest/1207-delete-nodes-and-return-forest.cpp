
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        root = removeNodes(root, to_delete_set, forest);

        if (root != nullptr) {
            forest.push_back(root);
        }

        return forest;
    }

private:
    TreeNode* removeNodes(TreeNode* node, unordered_set<int>& to_delete_set, vector<TreeNode*>& forest) {
        if (node == nullptr) {
            return nullptr;
        }

        node->left = removeNodes(node->left, to_delete_set, forest);
        node->right = removeNodes(node->right, to_delete_set, forest);

        if (to_delete_set.find(node->val) != to_delete_set.end()) {
            if (node->left != nullptr) {
                forest.push_back(node->left);
            }
            if (node->right != nullptr) {
                forest.push_back(node->right);
            }
            delete node;
            return nullptr;
        }

        return node;
    }
};