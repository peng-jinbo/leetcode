/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* temp = root;
        while(m > 1)
        {
            temp = temp->next;
            m--;
            n--;
        }
        ListNode* pos = temp->next->next;
        ListNode* first = temp->next;
        while(n > 1)
        {
            ListNode* temp1 = pos->next;
            pos->next = temp->next;
            temp->next = pos;
            first->next = temp1;
            pos = temp1;
            n--;
        }
        return root->next;
    }
};