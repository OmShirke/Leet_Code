class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        if(nums.size()==1){
            return new TreeNode(nums[0]);
        }

        int ind=nums.size()/2;
        TreeNode* root=new TreeNode(nums[ind]);

        vector<int> left(nums.begin(),nums.begin()+ind);
        vector<int> right(nums.begin()+ind+1,nums.end());

        root->left= sortedArrayToBST(left);
        root->right= sortedArrayToBST(right);

        return root;
    }
};