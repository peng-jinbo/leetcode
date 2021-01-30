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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root != NULL) dfs(root, "");
        return result;
        
    }
    void dfs(TreeNode* root, string temp)
    {
        if(root->left == NULL && root->right == NULL) 
        {
            temp += to_string(root->val);
            result.push_back(temp);
            return;
        }
        temp = temp + to_string(root->val) + "->";
        if(root->left != NULL) dfs(root->left, temp);
        if(root->right != NULL) dfs(root->right, temp);
    }
private:
    vector<string> result;
};