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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL)
        {
            return result;
        }
        else
        {
            stack<TreeNode*> s;
            s.push(root);
            while(!s.empty())
            {
                TreeNode* root = s.top();
                if(root->left==NULL&&root->right==NULL)
                {
                    result.push_back(root->val);
                    s.pop();
                }
                if(root->right!=NULL)
                {
                    s.push(root->right);
                    root->right = NULL;
                }
                if(root->left!=NULL)
                {
                    s.push(root->left);
                    root->left = NULL;
                }
            }
            return result;
        }
    }
};