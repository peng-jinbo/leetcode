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
    ListNode* sortList(ListNode* head) {
        head = mysort(head,NULL);
        return head;
    }
    ListNode* mysort(ListNode* head, ListNode* tail)
    {
        if(head == NULL) return head;
        if(head->next == tail)
        {
            head->next = NULL;
            return head;
        }
        ListNode* first = head;
        ListNode* second = head;
        while(second != tail)
        {
            first = first->next;
            second = second->next;
            if(second == tail) break;
            second = second->next;
        }
        return merge(mysort(head,first),mysort(first,tail));

    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};