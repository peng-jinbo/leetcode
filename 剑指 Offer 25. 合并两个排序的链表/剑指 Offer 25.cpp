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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* root = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                head->next = l1;
                head = head->next;
                l1 = l1->next;
            }
            else{
                head->next = l2;
                head = head->next;
                l2 = l2->next;
            }
        }
        ListNode* temp = (l1 == NULL)?l2:l1;
        head->next = temp;
        return root->next;
    }
};