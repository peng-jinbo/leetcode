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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* ret = getTree(head,NULL);
        return ret;
    }
    TreeNode* getTree(ListNode* head, ListNode* tail)
    {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = NULL;
        while(second->next!=tail)
        {
            temp = first;
            first = first->next;
            second = second->next;
            if(second->next != tail) second = second->next;
            else break;
        }
        if(temp!= NULL)
        {
            temp->next = NULL;
            temp = temp->next;
        }
        TreeNode* root = new TreeNode(first->val);
        root->left = getTree(head,temp);
        root->right = getTree(first->next,tail);
        return root;


    }
};