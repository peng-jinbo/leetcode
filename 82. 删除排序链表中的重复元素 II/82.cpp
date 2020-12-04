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
        ListNode* first = head;
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* temp = root;
        ListNode* second = head->next;
        while(second != NULL)
        {
            if(first->val!=second->val)
            {
                temp->next = first;
                temp = first;
                first = second;
                second = second->next;
            }
            else
            {
                while(second!=NULL&&first->val==second->val)
                {
                    second = second->next;
                }
                first = second;
                if(second != NULL) second = second->next;
                else break;
            }
        }
        temp->next = first;
        return root->next;
        
    }
};