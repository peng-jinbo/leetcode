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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return subTree(1,n);
    }
    vector<TreeNode*> subTree(int begin, int end)
    {
        if(begin > end) return {NULL};
        vector<TreeNode*> res;
        for(int i = begin; i <= end; i++)
        {
            vector<TreeNode*> lefts = subTree(begin,i-1);
            vector<TreeNode*> rights = subTree(i+1,end);
            for(auto leftT:lefts)
            {
                for(auto rightT:rights)
                {
                    TreeNode* temp = new TreeNode(i);
                    temp->left = leftT;
                    temp->right = rightT;
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};