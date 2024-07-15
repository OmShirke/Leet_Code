/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* current=root;

        while(current!=nullptr || !st.empty()){
            while(current!=nullptr){
                st.push(current);
                ans.push_back(current->val);
                current=current->left;
            }
            current=st.top();
            st.pop();
            current=current->right;
        }
        return ans;
    }
};