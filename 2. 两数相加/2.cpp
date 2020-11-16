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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
        ListNode* head = root;
        int count = 0;
        while(l1 != NULL && l2 != NULL)
        {
            int add = l1->val + l2->val + count;
            if(add > 9)
            {
                count = 1;
                add = add-10;
            }
            else
            {
                count = 0;
            }
            head->next = new ListNode(add);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* temp;
        if(l1 != NULL) temp = l1;
        else if(l2 != NULL) temp = l2;
        else{
            if(count == 1) head->next = new ListNode(1);
            return root->next;
        }
        while(temp != NULL)
        {
            int add = temp->val + count;
            if(add > 9)
            {
                count = 1;
                add = add-10;
            }
            else
            {
                count = 0;
            }
            head->next = new ListNode(add);
            head = head->next;
            temp = temp->next;
        }
        if(count == 1)
        {
            head->next = new ListNode(1);
        }
        return root->next;
    }
};