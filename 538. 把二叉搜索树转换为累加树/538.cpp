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
    TreeNode* convertBST(TreeNode* root) {
        int temp = back_num(root, 0);
        return root;
    }
    int back_num(TreeNode* root, int value)
    {
        if(root == NULL) return value;
        int temp = back_num(root->right, value);
        root->val = root->val + temp;
        temp = back_num(root->left, root->val);
        return temp;
    }
};