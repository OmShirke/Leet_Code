/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        stack<ListNode*> st;
        ListNode* curr=head;
        while(curr!=nullptr){
            st.push(curr);
            curr=curr->next;
        }
        ListNode* ans=st.top();
        st.pop();
        curr=ans;
        while(!st.empty()){
            curr->next=st.top();
            st.pop();
            curr=curr->next;
        }
        curr->next=nullptr;
        return ans;
    }
};