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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* temp = root;
        ListNode* first = head;
        ListNode* second = head->next;
        while(second != NULL)
        {
            temp->next = first;
            temp = first;
            while(second!=NULL && first->val == second->val)
            {
                second = second->next;
            }
            first = second;
            if(second == NULL) break;
            else second = second->next;
        }
        temp->next = first;
        return root->next;
    }
};