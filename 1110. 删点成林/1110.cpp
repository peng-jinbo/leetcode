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
    //后序遍历
    void process(TreeNode*& node, unordered_set<int>& set, vector<TreeNode*>& res)
    {
        if (node == NULL)
        {
            return;
        }
        process(node->left, set, res); //左边
        process(node->right, set, res); //右边
        if (set.find(node->val) != set.end()) //待删除的节点
        {
            if (node->left)
            {
                res.push_back(node->left);
            }

            if (node->right)
            {
                res.push_back(node->right);
            }

            node = nullptr;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> set(to_delete.begin(), to_delete.end());
        process(root, set, res);
        if(root)
        {
            res.push_back(root);
        }
        return res;
    }
};
