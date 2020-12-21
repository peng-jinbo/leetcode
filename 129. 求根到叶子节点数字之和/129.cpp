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
    int result = 0;
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root,0);
        return result;
    }
    void dfs(TreeNode* root, int temp)
    {
        if(root == NULL) return;
        if(root->left == NULL&&root->right == NULL)
        {
            result += temp*10+root->val;
            return;
        }
        temp = temp*10 + root->val;
        dfs(root->left,temp);
        dfs(root->right,temp);

    }
};