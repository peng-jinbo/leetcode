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
    // 链表操作
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* temp = head;
        ListNode* even = head->next;
        ListNode* odd = head->next->next;
        while(odd!=NULL)
        {
            ListNode* temp1 = temp->next;
            temp -> next = odd;
            even -> next = odd->next;
            odd -> next = temp1;
            temp = temp -> next;
            even = even -> next;
            if(even == NULL) break;
            odd = even -> next;
        }
        return head;
    }
};