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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int value = 0;
        int temp = get_deepth(root, value);
        return value-1;
    }
    int get_deepth(TreeNode* root, int& value)
    {
        if(root == NULL) return 0;
        int left = get_deepth(root->left, value);
        int right = get_deepth(root->right, value);
        value = max(left+right+1, value);
        return max(right, left) + 1;
    }
};