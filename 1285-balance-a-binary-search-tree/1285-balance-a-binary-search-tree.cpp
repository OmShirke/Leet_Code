/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> arr;
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        return bst(0, arr.size() - 1);
    }
    void traverse(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        traverse(root->left);
        arr.push_back(root);
        traverse(root->right);
    }
    TreeNode* bst(int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* root = arr[mid];
        root->left = bst(start, mid - 1);
        root->right = bst(mid + 1, end);
        return root;
    }
};