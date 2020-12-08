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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* error1 = NULL;
        TreeNode* error2 = NULL;
        TreeNode* pre = NULL;
        while(root != NULL || !s.empty())
        {
            while(root != NULL)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(pre == NULL) pre = root;
            else
            {
                if(pre->val >= root->val)
                {
                    error2 = root;
                    if(error1 == NULL) error1 = pre;
                    else break;
                }
            }
            pre = root;
            root = root->right;

        }
        swap(error1->val,error2->val);
    }
};