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
    int pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        dfs(root, temp, sum);
        return result;
    }
    void dfs(TreeNode* root, vector<int>& presum, int sum)
    {
        if(root == NULL) return;
        int n = presum.size();
        if(n == 0) presum.push_back(root->val);
        else presum.push_back(presum.back() + root->val);
        if(presum.back() == sum) result++;
        for(int i = 0; i < n; i++){
            if(presum.back()-presum[i] == sum) result++;
        }
        dfs(root->left, presum, sum);
        dfs(root->right, presum, sum);
        presum.pop_back();
    }
private:
    int result = 0;
};