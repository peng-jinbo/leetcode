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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* root = new ListNode();
        root->next = head;
        ListNode* front = root;
        while(head != NULL){
            if(head->val == val){
                front->next = head->next;
                break;
            }
            else{
                head = head->next;
                front = front->next;
            }
        }
        return root->next;
    }
};