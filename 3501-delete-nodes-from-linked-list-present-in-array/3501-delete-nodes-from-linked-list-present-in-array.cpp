class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numap(nums.begin(),nums.end());
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (numap.find(current->next->val) !=numap.end()) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};