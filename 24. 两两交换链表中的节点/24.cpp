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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head->next;
        
        head->next = temp->next;
        temp->next = head;
        head = temp;
        temp = head->next;
        ListNode* first = head->next->next;
        ListNode* second;
        while(first != NULL)
        {
            second = first->next;
            if(second == NULL) break;
            first->next = second->next;
            second->next = first;
            temp->next = second;
            temp = first;
            first = first->next;
        }
        return head;
    }
};