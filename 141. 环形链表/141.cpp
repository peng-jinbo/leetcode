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
    bool hasCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;
        bool tag = true;
        while(second != NULL&&(first!=second||tag))
        {
            tag = false;
            first = first->next;
            second = second->next;
            if(second == NULL) break;
            second = second->next;
        }
        return second != NULL;
    }
};