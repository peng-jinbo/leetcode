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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qt;
        vector<vector<int>> result;
        if(root == NULL) return result;
        qt.push(root);
        while(!qt.empty())
        {
            int num = qt.size();
            vector<int> temp;
            while(num > 0)
            {
                root = qt.front();
                qt.pop();
                temp.push_back(root->val);
                num--;
                if(root->left!=NULL) qt.push(root->left);
                if(root->right!=NULL) qt.push(root->right);
            }
            result.push_back(temp);
        }
        return result;
    }
};