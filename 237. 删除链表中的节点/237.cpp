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
    void deleteNode(ListNode* node) {
        ListNode* temp;
        bool tag = false;
        while(node->next != NULL)
        {
            node->val = node->next->val;
            if(!tag && node->next->next == NULL)
            {
                temp = node;
                tag = true;
            }
            node = node->next;
        }
        temp ->next =  NULL;
    }
};