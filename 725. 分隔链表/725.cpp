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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* head = root;
        int length = 0;
        while(head != NULL)
        {
            head = head->next;
            length++;
        }
        vector<ListNode*> result;
        int num1 = length/k;
        int num2 = length%k;
        head = root;
        for(int i = 0; i < num2; i++)
        {
            result.push_back(head);
            for(int j = 0; j <= num1; j++)
            {
                if( j == num1)
                {
                    ListNode* temp = head;
                    head = head->next;
                    temp->next = NULL;
                }
                else
                {
                    head = head->next;
                }
            }
        }
        while(head!=NULL)
        {
            result.push_back(head);
            for(int j = 0; j < num1 && head!=NULL; j++)
            {
               if( j == num1-1)
                {
                    ListNode* temp = head;
                    head = head->next;
                    temp->next = NULL;
                }
                else
                {
                    head = head->next;
                }
            }
        }
        while(length<k)
        {
            result.push_back(NULL);
            length++;
        }
        return result;
    }
};