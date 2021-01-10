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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* temp = root;
        while(head!=NULL)
        {
            if(head->val == val)
            {
                head = head->next;
            }
            else
            {
                temp->next = head;
                temp = temp->next;
                head = head->next;
            }
        }
        temp->next = NULL;
        return root->next;
    }
};