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
        ListNode* temp = nullptr;
        while(head != NULL){
            ListNode* temp1 = head->next;
            head->next = temp;
            temp = head;
            head = temp1;
        }
        return temp;
    }
};