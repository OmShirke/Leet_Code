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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* current=root;
        TreeNode* visited=nullptr;
        while(current != nullptr || !st.empty()){
            while(current!= nullptr){
                st.push(current);
                current=current->left;
            }
            current=st.top();

            if(current->right == nullptr || current->right== visited){
                ans.push_back(current->val);
                st.pop();
                visited=current;
                current=nullptr;
            }
            else{
                current=current->right;
            }
        }
        return ans;
    }
};