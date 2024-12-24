class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       if (!root){
            return true;
       }

       return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* left, TreeNode* right){
        if(!left && !right){
            return true;
        }
        if(!left || !right){
            return false;
        }
        return (left->val==right->val) && isMirror(left->left, right->right) && isMirror(left->right,right->left);
    }
};