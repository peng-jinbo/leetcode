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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp;
        while(n > 0)
        {
            second = second->next;
            n--;
        }
        if(second == NULL)
        {
            return head->next;
        }
        while(second != NULL)
        {
            temp = first;
            second = second->next;
            first = first->next;
        }
        temp -> next = first->next;
        return head;
    }
};