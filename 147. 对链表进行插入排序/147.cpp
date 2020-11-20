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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* sorted = head;
        ListNode* unsorted = head->next;
        while(unsorted != NULL)
        {
            if(sorted->val<=unsorted->val) sorted = sorted->next;
            else
            {
                ListNode* pre = root;
                while(pre->next->val <= unsorted->val)
                {
                    pre = pre->next;
                }
                sorted->next = unsorted->next;
                unsorted->next = pre->next;
                pre->next = unsorted;
            }
            unsorted = sorted->next;
        }
        return root->next;
    }
};