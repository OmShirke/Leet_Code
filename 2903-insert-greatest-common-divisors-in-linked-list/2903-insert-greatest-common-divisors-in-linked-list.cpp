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
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head->next;
        ListNode* left = head;
        while (current != nullptr) {
            int gcdValue = gcd(left->val, current->val);
            ListNode* gcdNode = new ListNode(gcdValue);
            left->next = gcdNode;
            gcdNode->next = current;
            left = current;
            current = current->next;
        }
        return head;
    }
};