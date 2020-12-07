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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = head;
        ListNode* root = new ListNode(0);
        ListNode* temp1 = root;
        root -> next = head;
        ListNode* temp = root;
        while(first != NULL)
        {
            if(first->val < x)
            {
                if(temp == temp1)
                {
                    temp = temp->next;
                    first = first->next;
                    temp1 = temp1->next;
                }
                else{
                    ListNode* second = temp->next;
                    temp->next = first;
                    temp1->next = first->next;
                    first->next = second;
                    temp = temp->next;
                    first = temp1->next;
                }
                
            }
            else
            {
                first = first->next;
                temp1 = temp1->next;
            }

        }
        return root->next;
    }
};