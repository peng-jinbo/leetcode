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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> qt;
        vector<vector<int>> result;
        if(root == NULL) return result;
        qt.push(root);
        bool tag = true;
        while(!qt.empty())
        {
            int num = qt.size();
            vector<int> temp;
            while(num > 0)
            {
                root = qt.front();
                qt.pop();
                num--;
                temp.push_back(root->val);
                if(root->left!= NULL) qt.push(root->left);
                if(root->right!= NULL) qt.push(root->right);
            }
            if(!tag)
            {
                reverse(temp.begin(),temp.end());
            }
            tag = !tag;
            result.push_back(temp);
        }
        return result;
    }
};