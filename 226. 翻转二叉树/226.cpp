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
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
    TreeNode* invert(TreeNode* node)
    {
        if(node == NULL) return NULL;
        else
        {
            TreeNode* temp = node->right;
            node->right = invert(node->left);
            node->left = invert(temp);
            return node;
        }
    }
};