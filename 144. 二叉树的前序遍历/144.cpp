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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
        {
            return result;
        }
        else
        {
            stack<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                TreeNode* root = q.top();
                result.push_back(root->val);
                q.pop();
                if(root->right!=NULL)
                {
                    q.push(root->right);
                }
                if(root->left!=NULL)
                {
                    q.push(root->left);
                }
            }
            return result;
        }
    }
};