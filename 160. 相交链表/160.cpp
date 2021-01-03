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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA != pB)
        {
            if(pA != NULL) pA = pA->next;
            else pA = headB;
            if(pB != NULL) pB = pB->next;
            else pB = headA;
        }
        return pA;
    }
};