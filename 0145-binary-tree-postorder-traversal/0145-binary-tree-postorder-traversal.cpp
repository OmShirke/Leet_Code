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
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr; // To keep track of the last visited node

        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            current = st.top();

            if (current->right == nullptr || current->right == lastVisited) {
                ans.push_back(current->val);
                st.pop();
                lastVisited = current;
                current = nullptr;
            } else {
                current = current->right;
            }
        }
        
        return ans;
    }
};
