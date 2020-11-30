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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* first = head;
        ListNode* second = head;
        int len = 0;
        while(second != NULL)
        {
            second = second->next;
            len++;
        }
        k = k%len;
        second = head;
        while(k > 0)
        {
            second = second->next;
            if(second == NULL) second = head;
            k--;
        }
        if(second == first) return head;
        while(second->next != NULL)
        {
            second = second->next;
            first = first->next;
        }
        second->next = head;
        ListNode* result= first->next;
        first->next = NULL;
        return result;
    }
};