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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int val = q.size();
            while(val > 0)
            {
                root = q.front();
                q.pop();
                val--;
                temp.push_back(root->val);
                if(root->left!=NULL) q.push(root->left);
                if(root->right!=NULL) q.push(root->right);
            }
            result.push_back(temp);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};