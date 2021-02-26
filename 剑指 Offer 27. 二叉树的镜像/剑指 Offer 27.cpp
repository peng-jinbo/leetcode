/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        swaptree(root);
        return root;
        
    }
    void swaptree(TreeNode* head)
    {
        if(head != NULL)
        {
            TreeNode* temp = head->left;
            head->left = head->right;
            head->right = temp;
            swaptree(head->left);
            swaptree(head->right);
        }
    }
};