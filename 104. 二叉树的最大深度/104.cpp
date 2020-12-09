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
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == NULL) return 0;
//         return max(maxDepth(root->left),maxDepth(root->right)) + 1;
//     }
// };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> qt;
        int result = 0;
        qt.push(root);
        while(!qt.empty())
        {
            int num = qt.size();
            while(num > 0)
            {
                root = qt.front();
                qt.pop();
                num--;
                if(root->left!=NULL) qt.push(root->left);
                if(root->right!=NULL) qt.push(root->right);
            }
            result++;
        }
        return result;
    }
};