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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        result.reserve(500);
        if(root == NULL) return result;
        queue<TreeNode*> q_node;
        q_node.push(root);
        while(!q_node.empty())
        {
            int sz = q_node.size();
            while(sz > 0)
            {
                root = q_node.front();
                q_node.pop();
                if(sz == 1)
                {
                    result.push_back(root->val);
                }
                if(root->left!=NULL) q_node.push(root->left);
                if(root->right!=NULL) q_node.push(root->right);
                sz--;
            }

        }
        return result;
    }
};