class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            for (int j = left; j <= right && curr != nullptr; j++) {
                ans[top][j] = curr->val;
                curr = curr->next;
            }
            top++;
            
            for (int i = top; i <= bottom && curr != nullptr; i++) {
                ans[i][right] = curr->val;
                curr = curr->next;
            }
            right--;
            
            for (int j = right; j >= left && curr != nullptr; j--) {
                ans[bottom][j] = curr->val;
                curr = curr->next;
            }
            bottom--;
            
            for (int i = bottom; i >= top && curr != nullptr; i--) {
                ans[i][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }
        
        return ans;
    }
};
