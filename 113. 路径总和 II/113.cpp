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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        backtrack(root,sum,temp);
        return result;
    }
    void backtrack(TreeNode* root, int sum, vector<int> temp)
    {
        if(root == NULL) return;
        temp.push_back(root->val);
        if(root->right == NULL && root->left==NULL && sum == root->val)
        {
            result.push_back(temp);
            return;
        }
        backtrack(root->left,sum-root->val,temp);
        backtrack(root->right, sum-root->val,temp);
        temp.pop_back();
    }
private:
    vector<vector<int>> result;
};