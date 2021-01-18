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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL;
        while(head != NULL)
        {
            ListNode* head1 = head;
            head = head->next;
            head1->next = temp;
            temp = head1;
        }
        return temp;
    }
};