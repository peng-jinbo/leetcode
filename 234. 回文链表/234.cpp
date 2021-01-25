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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp1 = NULL;
        ListNode* temp2;
        while(second != NULL)
        {
            if(second->next != NULL) second = second->next;
            else
            {
                second = first->next;
                first = temp1;
                break;
            }
            if(second->next != NULL)
            {
                second = second->next;
                temp2 = first->next;
                first->next = temp1;
                temp1 = first;
                first = temp2;
            }
            else{
                second = first->next;
                first->next = temp1;
                break;
            }
        }
        while(second!=NULL)
        {
            if(first->val!=second->val)
            {
                return false;
            }
            first=first->next;
            second = second->next;
        }
        return true;
    }
};